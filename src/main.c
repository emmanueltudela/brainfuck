#include <stdio.h>
#include <stdlib.h>

#include "brainfuck.h"

#define BUF_SIZE 1

void usage(char *exec) {
    printf("%s filename\n", exec);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[1]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot read %s\n", filename);
        exit(EXIT_FAILURE);
    }

    sbrainfuck *bf = sbrainfuck_create();

    char buffer[BUF_SIZE];
    size_t read = fread(buffer, BUF_SIZE * sizeof(char), 1, file);
    while(read > 0) {
        sbrainfuck_load_string(bf, buffer);
        read = fread(buffer, BUF_SIZE, 1, file);
    }

    sbrainfuck_compute(bf);

    sbrainfuck_free(bf);
    return EXIT_SUCCESS;
}
