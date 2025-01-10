#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

#include "linked_list.h"

void test_llist_create() {
    sllist *llist = sllist_create();
    assert(llist == NULL);

    sllist_free(llist);
}

void test_llist_free() {
    sllist *llist = sllist_create();

    // Empty
    sllist_free(llist);

    llist = sllist_create();

    // Non empty
    sllist_append(llist, 'a');

    sllist_free(llist);
}

void test_llist_empty() {
    sllist *llist = sllist_create();

    // Empty
    assert(sllist_empty(llist));

    // Non empty
    llist = sllist_append(llist, 'a');

    assert(!sllist_empty(llist));

    sllist_free(llist);
}

void test_llist_previous() {
    sllist *llist = sllist_create();
    llist = sllist_prepend(llist, 'a');
    llist = sllist_prepend(llist, 'b');

    sllist *prev = sllist_previous(llist);
    assert(sllist_value(prev) == 'b');

    sllist_free(llist);
    sllist_free(prev);
}

void test_llist_next() {
    sllist *llist = sllist_create();
    llist = sllist_append(llist, 'a');
    llist = sllist_append(llist, 'b');

    sllist *next = sllist_next(llist);
    assert(sllist_value(next) == 'b');

    sllist_free(llist);
    sllist_free(next);
}

void test_llist_append() {
    sllist *llist = sllist_create();
    llist = sllist_append(llist, 'a');
    llist = sllist_append(llist, 'b');
    llist = sllist_append(llist, 'c');

    sllist *next = sllist_next(llist);
    assert(sllist_value(next) == 'c');
    assert(sllist_value(sllist_next(next)) == 'b');

    sllist_free(llist);
    sllist_free(next);
}

void test_llist_prepend() {
    sllist *llist = sllist_create();
    llist = sllist_prepend(llist, 'a');
    llist = sllist_prepend(llist, 'b');
    llist = sllist_prepend(llist, 'c');

    sllist *prev = sllist_previous(llist);
    assert(sllist_value(prev) == 'c');
    assert(sllist_value(sllist_previous(prev)) == 'b');

    sllist_free(llist);
    sllist_free(prev);
}

void test_llist_value() {
    sllist *llist = sllist_create();
    llist = sllist_prepend(llist, 'a');

    assert(sllist_value(llist) == 'a');

    sllist_free(llist);
}

void test_llist_remove() {
    sllist *llist = sllist_create();
    llist = sllist_prepend(llist, 'a');
    llist = sllist_prepend(llist, 'b');
    llist = sllist_prepend(llist, 'c');

    llist = sllist_remove(llist);

    assert(sllist_value(llist) == 'c');

    llist = sllist_remove(llist);

    assert(sllist_value(llist) == 'b');

    llist = sllist_remove(llist);

    assert(sllist_empty(llist));

    sllist_free(llist);
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
    } else if (strcmp(testname, "llist_previous") == 0) {
        test_llist_previous();
    } else if (strcmp(testname, "llist_next") == 0) {
        test_llist_next();
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
