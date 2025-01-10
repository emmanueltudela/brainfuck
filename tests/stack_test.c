#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

#include "stack.h"

void test_stack_create() {
    sstack *stack = stack_create();
    stack_free(stack);
}

void test_stack_free() {
    sstack *stack = stack_create();
    stack_free(stack);
}

void test_stack_empty() {
    sstack *stack = stack_create();
    assert(stack_empty(stack));

    stack_push(stack, 'a');
    assert(!stack_empty(stack));
}

void test_stack_push() {
    sstack *stack = stack_create();

    stack_push(stack, 'a');
    stack_push(stack, 'b');

    assert(stack_pop(stack) == 'b');
    assert(stack_pop(stack) == 'a');

    // Test push over STACK_DEFL_SIZE for realloc
    for (int i = 0; i < 2 * STACK_DEFL_SIZE; i++) {
        stack_push(stack, 'a');
    }

    stack_free(stack);
}

void test_stack_pop() {
    sstack *stack = stack_create();

    stack_push(stack, 'a');
    stack_push(stack, 'b');

    assert(stack_pop(stack) == 'b');
    assert(stack_pop(stack) == 'a');

    assert(stack_empty(stack));

    // Don't test stack_pop on empty that causes error

    stack_free(stack);
}

void usage(char *exec) {
    printf("%s test_name\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *testname = argv[1];

    if (strcmp(testname, "stack_create") == 0) {
        test_stack_create();
    } else if (strcmp(testname, "stack_free") == 0) {
        test_stack_free();
    } else if (strcmp(testname, "stack_empty") == 0) {
        test_stack_empty();
    } else if (strcmp(testname, "stack_push") == 0) {
        test_stack_push();
    } else if (strcmp(testname, "stack_pop") == 0) {
        test_stack_pop();
    }

    return EXIT_SUCCESS;
}
