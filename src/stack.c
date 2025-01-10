#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct stack {
    char *arr;
    int size;
    int top;
} sstack;

sstack *sstack_create() {
    sstack *stack = malloc(sizeof(sstack));
    if (!stack) return NULL;

    char *arr = malloc(sizeof(char) * STACK_DEFL_SIZE);
    if (!arr) {
        free(stack);
        return NULL;
    }

    stack->arr = arr;
    stack->size = STACK_DEFL_SIZE;
    stack->top = 0;
}

void sstack_free(sstack *stack) {
    free(stack->arr);
    free(stack);
}

bool sstack_empty(sstack *stack) {
    if (!stack) {
        fprintf(stderr, "Cannot get empty from NULL stack\n");
        exit(EXIT_FAILURE);
    }

    return stack->top == 0;
}

void sstack_push(sstack *stack, char val) {
    if (!stack) {
        fprintf(stderr, "Cannot push to NULL stack\n");
        exit(EXIT_FAILURE);
    }

    // stack full
    if (stack->top >= stack->size) {
        stack->arr = realloc(stack->arr, sizeof(char) * stack->size * 2);
        stack->size = stack->size * 2;
    }

    stack->arr[stack->top] = val;
    stack->top++;
}

char sstack_pop(sstack *stack) {
    if (!stack) {
        fprintf(stderr, "Cannot pop from NULL stack\n");
        exit(EXIT_FAILURE);
    }

    if (sstack_empty(stack)) {
        fprintf(stderr, "Cannot pop from empty stack\n");
        exit(EXIT_FAILURE);
    }

    char val = stack->arr[stack->top - 1];
    stack->top--;

    return val;
}
