#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

#include "stripe.h"

void test_stripe_create() {
    sstripe *stripe = sstripe_create();
    sstripe_free(stripe);
}

void test_stripe_free() {
    sstripe *stripe = sstripe_create();
    sstripe_free(stripe);
}

void test_stripe_cursor() {
    sstripe *stripe = sstripe_create();

    assert(sstripe_cursor(stripe) == 0);

    sstripe_cursor_next(stripe);

    assert(sstripe_cursor(stripe) == 1);

    sstripe_free(stripe);
}

void test_stripe_cursor_previous() {
    sstripe *stripe = sstripe_create();

    assert(sstripe_cursor(stripe) == 0);

    sstripe_cursor_next(stripe);

    assert(sstripe_cursor(stripe) == 1);

    sstripe_cursor_previous(stripe);

    assert(sstripe_cursor(stripe) == 0);

    sstripe_free(stripe);
}

void test_stripe_cursor_next() {
    sstripe *stripe = sstripe_create();

    assert(sstripe_cursor(stripe) == 0);

    sstripe_cursor_next(stripe);

    assert(sstripe_cursor(stripe) == 1);

    sstripe_free(stripe);
}

void test_stripe_current() {
    sstripe *stripe = sstripe_create();

    assert(sstripe_current(stripe) == 0);

    sstripe_current_succ(stripe);

    assert(sstripe_current(stripe) == 1);

    sstripe_free(stripe);
}

void test_stripe_current_set() {
    sstripe *stripe = sstripe_create();

    sstripe_current_set(stripe, 10);

    assert(sstripe_current(stripe) == 10);

    sstripe_free(stripe);
}

void test_stripe_current_pred() {
    sstripe *stripe = sstripe_create();

    sstripe_current_set(stripe, 10);
    sstripe_current_pred(stripe);

    assert(sstripe_current(stripe) == 9);

    sstripe_free(stripe);
}

void test_stripe_current_succ() {
    sstripe *stripe = sstripe_create();

    sstripe_current_set(stripe, 10);
    sstripe_current_succ(stripe);

    assert(sstripe_current(stripe) == 11);

    sstripe_free(stripe);
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

    if (strcmp(testname, "stripe_create") == 0) {
        test_stripe_create();
    } else if (strcmp(testname, "stripe_free") == 0) {
        test_stripe_free();
    } else if (strcmp(testname, "stripe_cursor") == 0) {
        test_stripe_cursor();
    } else if (strcmp(testname, "stripe_cursor_previous") == 0) {
        test_stripe_cursor_previous();
    } else if (strcmp(testname, "stripe_cursor_next") == 0) {
        test_stripe_cursor_next();
    } else if (strcmp(testname, "stripe_current") == 0) {
        test_stripe_current();
    } else if (strcmp(testname, "stripe_current_set") == 0) {
        test_stripe_current_set();
    } else if (strcmp(testname, "stripe_current_pred") == 0) {
        test_stripe_current_pred();
    } else if (strcmp(testname, "stripe_current_succ") == 0) {
        test_stripe_current_succ();
    }

    return EXIT_SUCCESS;
}
