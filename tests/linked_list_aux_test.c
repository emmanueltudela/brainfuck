#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

#include "linked_list.h"
#include "linked_list_aux.h"

void test_llist_aux_first() {
    sllist *llist = sllist_create();

    llist = sllist_append_c(llist, 'a');

    assert(sllist_value_c(sllist_aux_first(llist)) == 'a');

    llist = sllist_prepend_c(llist, 'b');

    assert(sllist_value_c(sllist_aux_first(llist)) == 'b');

    llist = sllist_aux_remove_all(llist);

    sllist_free(llist);
}

void test_llist_aux_last() {
    sllist *llist = sllist_create();

    llist = sllist_append_c(llist, 'a');

    assert(sllist_value_c(sllist_aux_last(llist)) == 'a');

    llist = sllist_append_c(llist, 'b');

    assert(sllist_value_c(sllist_aux_last(llist)) == 'b');

    llist = sllist_aux_remove_all(llist);

    sllist_free(llist);
}

void test_llist_aux_append() {
    sllist *llist = sllist_create();

    llist = sllist_append_c(llist, 'a');
    llist = sllist_append_c(llist, 'b');

    llist = sllist_aux_append_c(llist, 'c');

    assert(sllist_value_c(sllist_next(sllist_next(llist))) == 'c');

    llist = sllist_aux_remove_all(llist);

    sllist_free(llist);
}

void test_llist_aux_prepend() {
    sllist *llist = sllist_create();

    llist = sllist_prepend_c(llist, 'a');
    llist = sllist_prepend_c(llist, 'b');

    llist = sllist_aux_prepend_c(llist, 'c');

    assert(sllist_value_c(sllist_previous(sllist_previous(llist))) == 'c');

    llist = sllist_aux_remove_all(llist);

    sllist_free(llist);
}

void test_llist_aux_append_i() {
    sllist *llist = sllist_create();

    llist = sllist_append_i(llist, 1);
    llist = sllist_append_i(llist, 2);

    llist = sllist_aux_append_i(llist, 3);

    assert(sllist_value_i(sllist_next(sllist_next(llist))) == 3);

    llist = sllist_aux_remove_all(llist);

    sllist_free(llist);
}

void test_llist_aux_prepend_i() {
    sllist *llist = sllist_create();

    llist = sllist_prepend_i(llist, 1);
    llist = sllist_prepend_i(llist, 2);

    llist = sllist_aux_prepend_i(llist, 3);

    assert(sllist_value_i(sllist_previous(sllist_previous(llist))) == 3);

    llist = sllist_aux_remove_all(llist);

    sllist_free(llist);
}

void test_llist_aux_append_c() {
    sllist *llist = sllist_create();

    llist = sllist_append_c(llist, 'a');
    llist = sllist_append_c(llist, 'b');

    llist = sllist_aux_append_c(llist, 'c');

    assert(sllist_value_c(sllist_next(sllist_next(llist))) == 'c');

    llist = sllist_aux_remove_all(llist);

    sllist_free(llist);
}

void test_llist_aux_prepend_c() {
    sllist *llist = sllist_create();

    llist = sllist_prepend_c(llist, 'a');
    llist = sllist_prepend_c(llist, 'b');

    llist = sllist_aux_prepend_c(llist, 'c');

    assert(sllist_value_c(sllist_previous(sllist_previous(llist))) == 'c');

    llist = sllist_aux_remove_all(llist);

    sllist_free(llist);
}

void test_llist_aux_remove_all() {
    sllist *llist = sllist_create();

    llist = sllist_append_c(llist, 'a');
    llist = sllist_append_c(llist, 'b');

    llist = sllist_aux_remove_all(llist);

    assert(llist == NULL);

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

    if (strcmp(testname, "llist_aux_append") == 0) {
        test_llist_aux_append();
    } else if (strcmp(testname, "llist_aux_prepend") == 0) {
        test_llist_aux_prepend();
    } else if (strcmp(testname, "llist_aux_remove_all") == 0) {
        test_llist_aux_remove_all();
    } else if (strcmp(testname, "llist_aux_first") == 0) {
        test_llist_aux_first();
    } else if (strcmp(testname, "llist_aux_last") == 0) {
        test_llist_aux_last();
    } else if (strcmp(testname, "llist_aux_append_i") == 0) {
        test_llist_aux_append_i();
    } else if (strcmp(testname, "llist_aux_prepend_i") == 0) {
        test_llist_aux_prepend_i();
    } else if (strcmp(testname, "llist_aux_append_c") == 0) {
        test_llist_aux_append_c();
    } else if (strcmp(testname, "llist_aux_prepend_c") == 0) {
        test_llist_aux_prepend_c();
    }

    return EXIT_SUCCESS;
}
