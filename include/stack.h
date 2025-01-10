#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack {
    char *arr;
    int size;
    int top;
} sstack;

sstack *stack_create();
void stack_free(sstack *stack);

void stack_push(sstack *stack, char val);
char stack_pop(sstack *stack);

#endif
