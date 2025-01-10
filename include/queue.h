#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

// Made to work with char for brainfuck
typedef struct queue squeue;

squeue *squeue_create();
void squeue_free();

bool squeue_empty();

void squeue_enqueue(squeue *queue, char val);
char squeue_dequeue(squeue *queue);

#endif
