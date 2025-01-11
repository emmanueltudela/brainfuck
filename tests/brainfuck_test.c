#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

#include "brainfuck.h"

void test_brainfuck_create() {
    sbrainfuck *bf = sbrainfuck_create();
    sbrainfuck_free(bf);
}

void test_brainfuck_free() {
    sbrainfuck *bf = sbrainfuck_create();
    sbrainfuck_free(bf);
}

void test_brainfuck_load_char() {
    sbrainfuck *bf = sbrainfuck_create();

    sbrainfuck_load_char(bf, '+');

    sbrainfuck_free(bf);
}

void test_brainfuck_load_string() {
    sbrainfuck *bf = sbrainfuck_create();

    sbrainfuck_load_string(bf, "+++");

    sbrainfuck_free(bf);
}

void test_brainfuck_finished() {
    sbrainfuck *bf = sbrainfuck_create();

    sbrainfuck_load_string(bf, "+++");

    sbrainfuck_iter(bf);

    assert(!sbrainfuck_finished(bf));

    sbrainfuck_compute(bf);

    assert(sbrainfuck_finished(bf));

    sbrainfuck_free(bf);
}

void test_brainfuck_iter() {
    sbrainfuck *bf = sbrainfuck_create();

    sbrainfuck_load_string(bf, "+++[>++[>++<-]<-]>>");

    sbrainfuck_iter(bf);

    assert(sbrainfuck_get_index(bf, 0) == 1);

    sbrainfuck_iter(bf);

    assert(sbrainfuck_get_index(bf, 0) == 2);

    sbrainfuck_compute(bf);

    sbrainfuck_print(bf);

    assert(sbrainfuck_get_index(bf, 2) == 12);

    assert(sbrainfuck_finished(bf));

    sbrainfuck_free(bf);
}

void test_brainfuck_compute() {
    sbrainfuck *bf = sbrainfuck_create();

    sbrainfuck_load_string(bf, "+++>++");

    sbrainfuck_compute(bf);

    assert(sbrainfuck_get_index(bf, 0) == 3);
    assert(sbrainfuck_get_index(bf, 1) == 2);
    assert(sbrainfuck_finished(bf));

    sbrainfuck_free(bf);
}

void test_brainfuck_get_index() {
    sbrainfuck *bf = sbrainfuck_create();

    sbrainfuck_load_string(bf, ">+++");

    sbrainfuck_compute(bf);

    assert(sbrainfuck_get_index(bf, 1) == 3);

    sbrainfuck_free(bf);
}

void test_brainfuck_print() {
    sbrainfuck *bf = sbrainfuck_create();

    sbrainfuck_load_string(bf, ">+++");

    sbrainfuck_compute(bf);

    sbrainfuck_print(bf);

    sbrainfuck_free(bf);
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

    if (strcmp(testname, "brainfuck_create") == 0) {
        test_brainfuck_create();
    } else if (strcmp(testname, "brainfuck_free") == 0) {
        test_brainfuck_free();
    } else if (strcmp(testname, "brainfuck_load_char") == 0) {
        test_brainfuck_load_char();
    } else if (strcmp(testname, "brainfuck_load_string") == 0) {
        test_brainfuck_load_string();
    } else if (strcmp(testname, "brainfuck_iter") == 0) {
        test_brainfuck_iter();
    } else if (strcmp(testname, "brainfuck_compute") == 0) {
        test_brainfuck_compute();
    } else if (strcmp(testname, "brainfuck_finished") == 0) {
        test_brainfuck_finished();
    } else if (strcmp(testname, "brainfuck_get_index") == 0) {
        test_brainfuck_get_index();
    } else if (strcmp(testname, "brainfuck_print") == 0) {
        test_brainfuck_print();
    } else if (strcmp(testname, "hw") == 0) {
        sbrainfuck *bf = sbrainfuck_create();

        sbrainfuck_load_string(bf, ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.");

        sbrainfuck_compute(bf);

        sbrainfuck_free(bf);
    }

    return EXIT_SUCCESS;
}
