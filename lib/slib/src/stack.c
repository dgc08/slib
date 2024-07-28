#include "../stack.h"
#include "../exceptions.h"

#include <stdlib.h>

Stack stack_new() {
    Stack new;
    new.top = NULL;
    new.size = 0;

    return new;
}

void stack_clear(Stack* stack) {
    while (stack->top != NULL) {
        stack_pop(stack);
    }
}

void* stack_at_offset(Stack* stack, size_t offset) {
    if (offset >= stack->size) {
        throw_exception("Tried to access element below Stack", SLIB_OutOfBoundsError);
        return NULL;
    }
    StackNode* node = stack->top;
    for (size_t j = 0; j < offset; j++) {
        node = (StackNode* ) node->previous;
    }

    return node->element;
}

void* stack_push_size(Stack* stack, size_t size) {
    StackNode* new_node = malloc(sizeof(StackNode));
    if (new_node == NULL) {
        throw_exception("Failed to allocate extra space for new element (node)", SLIB_MemoryError);
        return NULL;
    }

    new_node->previous =  (struct StackNode* )stack->top;

    new_node->element = malloc(size);
    if (new_node->element == NULL) {
        free(new_node);
        throw_exception("Failed to allocate extra space for new element (element)", SLIB_MemoryError);
        return NULL;
    }
    stack->top = new_node;
    stack->size++;

    return new_node->element;
}


void stack_pop(Stack* stack) {
    if (stack->top == NULL) {
        throw_exception("Tried to pop element off empty Stack", SLIB_OutOfBoundsError);
    }
    StackNode* popped = stack->top;
    free(popped->element);
    stack->top = (StackNode* ) popped->previous;
    stack->size--;
}
