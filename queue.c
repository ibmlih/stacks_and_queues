#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

typedef struct queue_node
{
    void *data;
    struct queue_node *next;
} queue_node;

struct queue
{
    queue_node *front, *back;
    int size;
};

queue_t queue_create(void)
{
    queue_t q = malloc(sizeof(struct queue));

    if (!q)
        return NULL;

    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int queue_destroy(queue_t queue)
{
    if (!queue || queue->size > 0)
        return -1;

    free(queue);
    return 0;
}

int queue_enqueue(queue_t queue, void *data)
{
    if (!queue || !data)
        return -1;

    queue_node *node = malloc(sizeof(queue_node));

    if (!node)
        return -1;

    node->data = data;
    node->next = NULL;

    if (!queue->front) {
        // Queue is empty
        queue->front = node;
    } else {
        // Queue is not empty
        queue->back->next = node;
    }

    queue->back = node;
    queue->size++;
    return 0;
}

int queue_dequeue(queue_t queue, void **data)
{
    if (!queue || !queue->front || !data)
        return -1;

    *data = queue->front->data;
    queue_node *temp = queue->front->next;
    free(queue->front);

    if (!temp) {
        // Only one item in queue
        queue->front = NULL;
        queue->back = NULL;
    } else {
        // More than one item in queue
        queue->front = temp;
    }

    queue->size--;
    return 0;
}

int queue_delete(queue_t queue, void *data)
{
    if (!queue || !data)
        return -1;

    queue_node *ptr, *prev = NULL;

    for (ptr = queue->front; ptr && ptr->data != data; ptr = ptr->next)
        prev = ptr;

    // Item not found
    if (!ptr || ptr->data != data)
        return -1;

    if (prev)
        // Item NOT at the front
        prev->next = ptr->next;
    else
        // Item at the front
        queue->front = ptr->next;

    if (!ptr->next) {
        // Change queue->back if last item was deleted from the queue
        if (prev)
            queue->back = prev;
        else
            queue->back = queue->front;
    }

    free(ptr);
    queue->size--;
    return 0;
}

int queue_length(queue_t queue)
{
    return !queue ? -1 : queue->size;
}
