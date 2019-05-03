#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

struct stack
{
    void **array;
    int size;
};

stack_type stack_create(size_t capacity)
{
    stack_type s = malloc(sizeof(struct stack));

    if (!s)
        return NULL;

    s->array = malloc(capacity * sizeof(void*));
    s->size = 0;
    return s;
}

int stack_destroy(stack_type stack)
{
    if (!stack || stack->size > 0)
        return -1;

    free(stack->array);
    free(stack);
    return 0;
}

int stack_push(stack_type stack, void *data)
{
    if (!stack || !data)
        return -1;

    stack->array[stack->size++] = data;
    return 0;
}

int stack_pop(stack_type stack, void **data)
{
    if (!stack || !stack->size || !data)
        return -1;

    *data = stack->array[--stack->size];

    return 0;
}

int stack_length(stack_type stack)
{
    return !stack ? -1 : stack->size;
}