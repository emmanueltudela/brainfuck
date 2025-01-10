#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "queue.h"

typedef struct queue {
    sllist *llist;
} squeue;

squeue *squeue_create() {
    return NULL;
}

void squeue_free() {
}

bool squeue_empty() {
    return false;
}

void squeue_enqueue(squeue *queue, char val) {
}

char squeue_dequeue(squeue *queue) {
    return '\0';
}
