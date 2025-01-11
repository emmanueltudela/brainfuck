#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

#include "linked_list.h"

// Made to work with char for brainfuck
typedef struct queue squeue;

squeue *squeue_create();
void squeue_free(squeue *queue);

/* Is queue empty
 */
bool squeue_empty(squeue *queue);

void squeue_enqueue(squeue *queue, char val);
char squeue_dequeue(squeue *queue);

/* Double ended queue put at beginning of queue and eject from end of queue
 */
void squeue_push(squeue *queue, char val);
char squeue_eject(squeue *queue);

#endif
