#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "linked_list_aux.h"
#include "queue.h"

typedef struct queue {
    sllist *llist;
} squeue;

squeue *squeue_create() {
    squeue *queue = malloc(sizeof(squeue));
    if (!queue) return NULL;

    queue->llist = sllist_create();
    return queue;
}

void squeue_free(squeue *queue) {
    queue->llist = sllist_aux_remove_all(queue->llist);
    sllist_free(queue->llist);
    free(queue);
}

bool squeue_empty(squeue *queue) {
    return sllist_empty(queue->llist);
}

void squeue_enqueue(squeue *queue, char val) {
    queue->llist = sllist_aux_append(queue->llist, val);
}

char squeue_dequeue(squeue *queue) {
    if (!queue) {
        fprintf(stderr, "Cannot dequeue from NULL queue\n");
        exit(EXIT_FAILURE);
    }

    sllist *first = sllist_aux_first(queue->llist);
    char res = sllist_value(first);
    queue->llist = sllist_remove(first);
    return res;
}

void squeue_push(squeue *queue, char val) {
    queue->llist = sllist_aux_prepend(queue->llist, val);
}

char squeue_eject(squeue *queue) {
    if (!queue) {
        fprintf(stderr, "Cannot dequeue from NULL queue\n");
        exit(EXIT_FAILURE);
    }

    sllist *last = sllist_aux_last(queue->llist);
    char res = sllist_value(last);
    queue->llist = sllist_remove(last);
    return res;
}
