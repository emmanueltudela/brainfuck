#ifndef __STACK_H__
#define __STACK_H__

#define STACK_DEFL_SIZE 10

// made to work with char for brainfuck
typedef struct stack sstack;

sstack *stack_create();
void stack_free(sstack *stack);

void stack_push(sstack *stack, char val);
char stack_pop(sstack *stack);

#endif
