#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

#define STACK_DEFL_SIZE 10

typedef struct stack sstack;

sstack *sstack_create();
void sstack_free(sstack *stack);

bool sstack_empty(sstack *stack);

void sstack_push(sstack *stack, char val);
char sstack_pop(sstack *stack);

#endif
