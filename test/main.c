#include "slib/exceptions.h"
#include "slib/program.h"
#include "slib/stack.h"


#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_stack();
int main(int argc, char *argv[]) {
    test_stack();

    setup_slib_args(argv, argc);
    printf("Named: %s\n", get_named_argument("-a="));

    SLIB_try();
    throw_exception("hey", SLIB_OSError);
    int e = SLIB_except();
    printf("First: %d %s \n", e, SLIB_get_error_message());

    SLIB_try();
    puts("woohoo");
    e = SLIB_except();
    printf("Second: %d %s \n", e, SLIB_get_error_message());
}

void test_stack() {
    Stack stack = stack_new();

    // Test 1: Pushing and popping integers
    int value1 = 10;
    int value2 = 20;
    stack_push(stack, value1, int);
    stack_push(stack, value2, int);

    assert(stack.size == 2);
    assert(stack_at(stack, 0, int) == value2);
    assert(stack_at(stack, 1, int) == value1);

    stack_pop(&stack);
    assert(stack.size == 1);
    assert(stack_at(stack, 0, int) == value1);

    stack_pop(&stack);
    assert(stack.size == 0);

    // Test 2: Pushing and popping strings
    char* str1 = "hello";
    char* str2 = "world";
    stack_push(stack, str1, char*);
    stack_push(stack, str2, char*);

    //printf("Ez %s %s\n", stack_at(stack, 0, char*), stack_at(stack, 1, char*));

    assert(stack.size == 2);
    assert(strcmp(stack_at(stack, 0, char*), str2) == 0);
    assert(strcmp(stack_at(stack, 1, char*), str1) == 0);

    stack_pop(&stack);
    assert(stack.size == 1);
    assert(strcmp(stack_at(stack, 0, char*), str1) == 0);

    stack_pop(&stack);
    assert(stack.size == 0);

    // Test 3: Accessing out of bounds
    SLIB_try();
    stack_at(stack, 0, int);
    assert(SLIB_except() == SLIB_OutOfBoundsError);

    // Test 4: Pushing and popping custom structs
    typedef struct {
        int a;
        float b;
    } CustomStruct;

    CustomStruct cs1 = {1, 1.1f};
    CustomStruct cs2 = {2, 2.2f};

    stack_push(stack, cs1, CustomStruct);
    stack_push(stack, cs2, CustomStruct);

    assert(stack.size == 2);
    CustomStruct res = stack_at(stack, 0, CustomStruct);
    assert(res.a == 2 && res.b == 2.2f);
    res = stack_at(stack, 1, CustomStruct);
    assert(res.a == 1 && res.b == 1.1f);

    stack_pop(&stack);
    assert(stack.size == 1);
    res = stack_at(stack, 0, CustomStruct);
    assert(res.a == 1 && res.b == 1.1f);


    stack_clear(&stack);
    assert(stack_is_empty(stack));

    printf("All stack tests passed!\n");
}
