#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

#include "linked_list.h"

void test_llist_create() {
}

void test_llist_free() {
}

void test_llist_empty() {
}

void test_llist_append() {
}

void test_llist_prepend() {
}

void test_llist_value() {
}

void test_llist_remove() {
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

    if (strcmp(testname, "llist_create") == 0) {
        test_llist_create();
    } else if (strcmp(testname, "llist_free") == 0) {
        test_llist_free();
    } else if (strcmp(testname, "llist_empty") == 0) {
        test_llist_empty();
    } else if (strcmp(testname, "llist_append") == 0) {
        test_llist_append();
    } else if (strcmp(testname, "llist_prepend") == 0) {
        test_llist_prepend();
    } else if (strcmp(testname, "llist_value") == 0) {
        test_llist_value();
    } else if (strcmp(testname, "llist_remove") == 0) {
        test_llist_remove();
    }

    return EXIT_SUCCESS;
}
