#ifndef SLIB_STACK_H_
#define SLIB_STACK_H_

#include "./types.h"

#define stack_at(stack, offset, T) (*(T *)stack_at_offset(&stack, offset))
#define stack_push(stack, object, T) (*(T *)stack_push_size(&stack, sizeof(T)) = object)
#define stack_is_empty(stack) ((stack).size == 0)

typedef struct {
    struct StackNode* previous;
    void* element;
} StackNode;

typedef struct {
    StackNode* top;
    size_t size;
} Stack;

Stack stack_new();
void stack_clear(Stack* stack);

void* stack_at_offset(Stack* stack, size_t offset);

void* stack_push_size(Stack* stack, size_t size);
void stack_pop(Stack* stack);

#endif // SLIB_STACK_H_
