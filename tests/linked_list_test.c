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
    llist = sllist_append_c(llist, 'a');

    sllist_free(llist);
}

void test_llist_empty() {
    sllist *llist = sllist_create();

    // Empty
    assert(sllist_empty(llist));

    // Non empty
    llist = sllist_append_c(llist, 'a');

    assert(!sllist_empty(llist));

    sllist_free(llist);
}

void test_llist_previous() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_c(llist, 'a');
    llist = sllist_prepend_c(llist, 'b');

    sllist *prev = sllist_previous(llist);
    assert(sllist_value_c(prev) == 'b');

    sllist_free(llist);
    sllist_free(prev);
}

void test_llist_next() {
    sllist *llist = sllist_create();
    llist = sllist_append_c(llist, 'a');
    llist = sllist_append_c(llist, 'b');

    sllist *next = sllist_next(llist);
    assert(sllist_value_c(next) == 'b');

    sllist_free(llist);
    sllist_free(next);
}

void test_llist_append() {
    sllist *llist = sllist_create();
    llist = sllist_append_c(llist, 'a');
    llist = sllist_append_c(llist, 'b');
    llist = sllist_append_c(llist, 'c');

    sllist *next = sllist_next(llist);
    assert(sllist_value_c(next) == 'c');
    assert(sllist_value_c(sllist_next(next)) == 'b');

    for (int i = 0; i < 3; i++) {
        llist = sllist_remove(llist);
    }

    sllist_free(llist);
}

void test_llist_prepend() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_c(llist, 'a');
    llist = sllist_prepend_c(llist, 'b');
    llist = sllist_prepend_c(llist, 'c');

    sllist *prev = sllist_previous(llist);
    assert(sllist_value_c(prev) == 'c');
    assert(sllist_value_c(sllist_previous(prev)) == 'b');

    for (int i = 0; i < 3; i++) {
        llist = sllist_remove(llist);
    }

    sllist_free(llist);
}

void test_llist_append_i() {
    sllist *llist = sllist_create();
    llist = sllist_append_i(llist, 1);
    llist = sllist_append_i(llist, 2);
    llist = sllist_append_i(llist, 3);

    sllist *next = sllist_next(llist);
    assert(sllist_value_i(next) == 3);
    assert(sllist_value_i(sllist_next(next)) == 2);

    for (int i = 0; i < 3; i++) {
        llist = sllist_remove(llist);
    }

    sllist_free(llist);
}

void test_llist_prepend_i() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_c(llist, 1);
    llist = sllist_prepend_c(llist, 2);
    llist = sllist_prepend_c(llist, 3);

    sllist *prev = sllist_previous(llist);
    assert(sllist_value_c(prev) == 3);
    assert(sllist_value_c(sllist_previous(prev)) == 2);

    for (int i = 0; i < 3; i++) {
        llist = sllist_remove(llist);
    }

    sllist_free(llist);
}

void test_llist_append_c() {
    sllist *llist = sllist_create();
    llist = sllist_append_c(llist, 'a');
    llist = sllist_append_c(llist, 'b');
    llist = sllist_append_c(llist, 'c');

    sllist *next = sllist_next(llist);
    assert(sllist_value_c(next) == 'c');
    assert(sllist_value_c(sllist_next(next)) == 'b');

    for (int i = 0; i < 3; i++) {
        llist = sllist_remove(llist);
    }

    sllist_free(llist);
}

void test_llist_prepend_c() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_c(llist, 'a');
    llist = sllist_prepend_c(llist, 'b');
    llist = sllist_prepend_c(llist, 'c');

    sllist *prev = sllist_previous(llist);
    assert(sllist_value_c(prev) == 'c');
    assert(sllist_value_c(sllist_previous(prev)) == 'b');

    for (int i = 0; i < 3; i++) {
        llist = sllist_remove(llist);
    }

    sllist_free(llist);
}

void test_llist_value() {
    sllist *llist = sllist_create();

    llist = sllist_prepend_c(llist, 'a');

    assert(sllist_value_c(llist) == 'a');

    sllist_free(llist);
}

void test_llist_value_i() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_c(llist, 'a');

    assert(sllist_value_c(llist) == 'a');

    sllist_free(llist);
}

void test_llist_value_c() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_i(llist, 1);

    assert(sllist_value_i(llist) == 1);

    sllist_free(llist);
}

void test_llist_remove() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_c(llist, 'a');
    llist = sllist_prepend_c(llist, 'b');
    llist = sllist_prepend_c(llist, 'c');

    llist = sllist_remove(llist);

    assert(sllist_value_c(llist) == 'c');

    llist = sllist_remove(llist);

    assert(sllist_value_c(llist) == 'b');

    llist = sllist_remove(llist);

    assert(sllist_empty(llist));

    sllist_free(llist);
}

void test_llist_set() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_i(llist, 1);

    sllist_set_i(llist, 2);

    assert(sllist_value_i(llist) == 2);

    sllist_free(llist);
}

void test_llist_set_i() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_i(llist, 1);

    sllist_set_i(llist, 2);

    assert(sllist_value_i(llist) == 2);

    sllist_free(llist);
}

void test_llist_set_c() {
    sllist *llist = sllist_create();
    llist = sllist_prepend_c(llist, 'a');

    sllist_set_c(llist, 'b');

    assert(sllist_value_c(llist) == 'b');

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
    } else if (strcmp(testname, "llist_append_i") == 0) {
        test_llist_append_i();
    } else if (strcmp(testname, "llist_prepend_i") == 0) {
        test_llist_prepend_i();
    } else if (strcmp(testname, "llist_append_c") == 0) {
        test_llist_append_c();
    } else if (strcmp(testname, "llist_prepend_c") == 0) {
        test_llist_prepend_c();
    } else if (strcmp(testname, "llist_value_i") == 0) {
        test_llist_value_i();
    } else if (strcmp(testname, "llist_value_c") == 0) {
        test_llist_value_c();
    } else if (strcmp(testname, "llist_set") == 0) {
        test_llist_set();
    } else if (strcmp(testname, "llist_set_i") == 0) {
        test_llist_set_i();
    } else if (strcmp(testname, "llist_set_c") == 0) {
        test_llist_set_c();
    }

    return EXIT_SUCCESS;
}
