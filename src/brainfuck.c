#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "queue.h"
#include "stripe.h"

typedef struct brainfuck {
    sstripe *stripe;    // Result stripe
    squeue *exec;       // Execution queue
    sstack *loop_reg;   // Execution memory
    int in_loop;        // Current loop index
    int loop_jmp;       // Loop memory when jumping
    bool finished;      // Is the computation finished
} sbrainfuck;

sbrainfuck *sbrainfuck_create() {
    sbrainfuck *bf = malloc(sizeof(sbrainfuck));
    if (!bf) return NULL;

    sstripe *stripe = sstripe_create();
    if (!stripe) {
        free(bf);
        return NULL;
    }

    squeue *exec = squeue_create();
    if (!exec) {
        sstripe_free(stripe);
        free(bf);
        return NULL;
    }

    sstack *loop_reg = sstack_create();
    if (!loop_reg) {
        sstripe_free(stripe);
        squeue_free(exec);
        free(bf);
        return NULL;
    }

    bf->stripe = stripe;
    bf->exec = exec;
    bf->loop_reg = loop_reg;
    bf->in_loop = 0;
    bf->loop_jmp = 0;
    bf->finished = false;
    return bf;
}

void sbrainfuck_free(sbrainfuck *bf) {
    sstripe_free(bf->stripe);
    squeue_free(bf->exec);
    sstack_free(bf->loop_reg);
    free(bf);
}

void sbrainfuck_load_char(sbrainfuck *bf, char c) {
    if (!bf) {
        fprintf(stderr, "Cannot load char in NULL brainfuck execution\n");
        exit(EXIT_FAILURE);
    }

    squeue_enqueue(bf->exec, c);
}

void sbrainfuck_load_string(sbrainfuck *bf, char *c) {
    if (!bf) {
        fprintf(stderr, "Cannot load string in NULL brainfuck execution\n");
        exit(EXIT_FAILURE);
    }

    while (*c != '\0') {
        sbrainfuck_load_char(bf, *c);
        c++;
    }
}

bool sbrainfuck_finished(sbrainfuck *bf) {
    if (!bf) {
        fprintf(stderr, "Cannot get finished of NULL brainfuck execution\n");
        exit(EXIT_FAILURE);
    }

    return bf->finished;
}

void sbrainfuck_iter(sbrainfuck *bf) {
    if (!bf) {
        fprintf(stderr, "Cannot iterate NULL brainfuck execution\n");
        exit(EXIT_FAILURE);
    }

    if (squeue_empty(bf->exec)) {
        bf->finished = true;
        return;
    }

    char c = squeue_dequeue(bf->exec);
    sstack_push(bf->loop_reg, c);

    if (bf->loop_jmp != 0 && c == '[') {
        bf->in_loop++;
        return;
    } else if (bf->loop_jmp != 0 && c == ']') {
        if (bf->loop_jmp == bf->in_loop) {
            bf->loop_jmp = 0;
        }
        bf->in_loop--;
        return;
    } else if (bf->loop_jmp != 0) {
        return;
    }

    switch (c) {
        case '+':
            sstripe_current_succ(bf->stripe);
            break;
        case '-':
            sstripe_current_pred(bf->stripe);
            break;
        case '>':
            sstripe_cursor_next(bf->stripe);
            break;
        case '<':
            sstripe_cursor_previous(bf->stripe);
            break;
        case '.':
            printf("%c", (char)sstripe_current(bf->stripe));
            break;
        case ',':
            int o = getchar();
            sstripe_current_set(bf->stripe, (char)o);
            break;
        case '[':
            bf->in_loop++;

            if (sstripe_current(bf->stripe) == 0) {
                bf->loop_jmp = bf->in_loop;
            }

            break;
        case ']':
            bf->in_loop--;

            int loop_count = 0;

            // Just registered loop end
            char c = sstack_pop(bf->loop_reg);
            // Force it at beginning of execution queue
            squeue_push(bf->exec, c);

            c = sstack_pop(bf->loop_reg);
            while (c != '[' || loop_count != 0) {
                if (c == ']') {
                    loop_count++;
                } else if (c == '[') {
                    loop_count--;
                }

                // Requeue the loop code at head of execution queue
                squeue_push(bf->exec, c);

                c = sstack_pop(bf->loop_reg);
            }
            // Push the last '[' read because it's part of the loop code
            squeue_push(bf->exec, c);

            break;
        default:
            return;
    }
    return;
}

void sbrainfuck_compute(sbrainfuck *bf) {
    if (!bf) {
        fprintf(stderr, "Cannot compute NULL brainfuck execution\n");
        exit(EXIT_FAILURE);
    }

    while (!sbrainfuck_finished(bf)) {
        sbrainfuck_iter(bf);
    }
}

int sbrainfuck_get_index(sbrainfuck *bf, int n) {
    if (!bf) {
        fprintf(stderr, "Cannot get index of NULL brainfuck execution\n");
        exit(EXIT_FAILURE);
    }

    sstripe_get_index(bf->stripe, n);
}

void sbrainfuck_print(sbrainfuck *bf) {
    if (!bf) {
        fprintf(stderr, "Cannot print NULL brainfuck execution\n");
        exit(EXIT_FAILURE);
    }

    sstripe_print(bf->stripe);
}
