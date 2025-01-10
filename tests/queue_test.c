#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

#include "linked_list.h"
#include "queue.h"

void test_queue_create() {
    squeue *queue = squeue_create();
    squeue_free(queue);
}

void test_queue_free() {
    squeue *queue = squeue_create();
    squeue_free(queue);
}

void test_queue_empty() {
    squeue *queue = squeue_create();

    assert(squeue_empty(queue));

    squeue_enqueue(queue, 'a');

    assert(!squeue_empty(queue));

    squeue_free(queue);
}

void test_queue_enqueue() {
    squeue *queue = squeue_create();

    squeue_enqueue(queue, 'a');
    squeue_enqueue(queue, 'b');

    assert(squeue_dequeue(queue) == 'a');
    assert(squeue_dequeue(queue) == 'b');

    squeue_free(queue);
}

void test_queue_dequeue() {
    squeue *queue = squeue_create();

    squeue_enqueue(queue, 'a');
    squeue_enqueue(queue, 'b');

    squeue_dequeue(queue);
    squeue_dequeue(queue);

    assert(squeue_empty(queue));

    squeue_free(queue);
}

void test_queue_push() {
    squeue *queue = squeue_create();

    squeue_push(queue, 'a');
    squeue_push(queue, 'b');

    assert(squeue_dequeue(queue) == 'b');
    assert(squeue_dequeue(queue) == 'a');

    squeue_free(queue);
}

void test_queue_eject() {
    squeue *queue = squeue_create();

    squeue_enqueue(queue, 'a');
    squeue_enqueue(queue, 'b');

    assert(squeue_eject(queue) == 'b');
    assert(squeue_eject(queue) == 'a');

    assert(squeue_empty(queue));

    squeue_free(queue);
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

    if (strcmp(testname, "queue_create") == 0) {
        test_queue_create();
    } else if (strcmp(testname, "queue_free") == 0) {
        test_queue_free();
    } else if (strcmp(testname, "queue_empty") == 0) {
        test_queue_empty();
    } else if (strcmp(testname, "queue_enqueue") == 0) {
        test_queue_enqueue();
    } else if (strcmp(testname, "queue_dequeue") == 0) {
        test_queue_dequeue();
    } else if (strcmp(testname, "queue_push") == 0) {
        test_queue_push();
    } else if (strcmp(testname, "queue_eject") == 0) {
        test_queue_eject();
    }

    return EXIT_SUCCESS;
}
