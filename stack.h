#ifndef _STACK_H
#define _STACK_H

/*
 * stack_type - stack type
 *
 * A stack is a FILO data structure. Data items are pushed one after the
 * other.  When popping, the stack must returned the last pushed item
 * first and so on.
 */
typedef struct stack *stack_type;

/*
 * stack_create - Allocate an empty stack with size @capacity
 * @capacity: size of the stack
 *
 * Create a new object of type 'struct stack' with size @capacity
 * and return its address.
 *
 * Return: Pointer to new empty stack. NULL in case of failure when allocating
 * the new stack.
 */
stack_type stack_create(size_t capacity);

/*
 * stack_destroy - Deallocate a stack
 * @stack: stack to deallocate
 *
 * Deallocate the memory associated to the stack object pointed by @stack.
 *
 * Return: -1 if @stack is NULL of if @stack is not empty. 0 if @stack was
 * successfully destroyed.
 */
int stack_destroy(stack_type stack);

/*
 * stack_push - Push data item
 * @stack: stack in which to push item
 * @data: Address of data item to push
 *
 * Push the address contained in @data in the stack @stack.
 *
 * Return: -1 if @stack or @data are NULL, or in case of memory allocation error
 * when pushing. 0 if @data was successfully pushed in @stack.
 */
int stack_push(stack_type stack, void *data);

/*
 * stack_pop - Pop data item
 * @stack: stack in which to pop item
 * @data: Address of data pointer where item is received
 *
 * Remove the most recent item of stack @stack and assign this item (the value of a
 * pointer) to @data.
 *
 * Return: -1 if @stack or @data are NULL, or if the stack is empty. 0 if @data
 * was set with the most recent item available in @stack.
 */
int stack_pop(stack_type stack, void **data);

/*
 * stack_length - stack length
 * @stack: stack to get the length of
 *
 * Return the length of stack @stack.
 *
 * Return: -1 if @stack is NULL. Length of @stack otherwise.
 */
int stack_length(stack_type stack);

#endif /* _STACK_H */