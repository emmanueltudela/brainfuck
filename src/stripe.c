#include <stdio.h>
#include <stdlib.h>

#include "stripe.h"
#include "linked_list.h"
#include "linked_list_aux.h"

typedef struct stripe {
    sllist *llist;
    int size;
    int cursor;
} sstripe;

sstripe *sstripe_create() {
    sstripe *stripe = malloc(sizeof(sstripe));
    if (!stripe) return NULL;

    sllist *llist = sllist_create();
    llist = sllist_append_i(llist, 0);

    stripe->llist = llist;
    stripe->size = 1;
    stripe->cursor = 0;
    return stripe;
}

void sstripe_free(sstripe *stripe) {
    stripe->llist = sllist_aux_remove_all(stripe->llist);
    sllist_free(stripe->llist);
    free(stripe);
}

int sstripe_cursor(sstripe *stripe) {
    if (!stripe) {
        fprintf(stderr, "Cannot get cursor from NULL stripe\n");
        exit(EXIT_FAILURE);
    }

    return stripe->cursor;
}

void sstripe_cursor_previous(sstripe *stripe) {
    if (!stripe) {
        fprintf(stderr, "Cannot get cursor previous from NULL stripe\n");
        exit(EXIT_FAILURE);
    }

    if (stripe->cursor == 0) {
        fprintf(stderr, "Cannot get cursor previous when already at 0\n");
        exit(EXIT_FAILURE);
    }

    stripe->cursor--;
    stripe->llist = sllist_previous(stripe->llist);
}

void sstripe_cursor_next(sstripe *stripe) {
    if (!stripe) {
        fprintf(stderr, "Cannot get cursor next from NULL stripe\n");
        exit(EXIT_FAILURE);
    }

    if (sllist_empty(sllist_next(stripe->llist))) {
        stripe->llist = sllist_append_i(stripe->llist, 0);
        stripe->size++;
    }
    stripe->cursor++;
    stripe->llist = sllist_next(stripe->llist);
}

int sstripe_current(sstripe *stripe) {
    if (!stripe) {
        fprintf(stderr, "Cannot get current from NULL stripe\n");
        exit(EXIT_FAILURE);
    }

    return sllist_value_i(stripe->llist);
}

void sstripe_current_set(sstripe *stripe, int val) {
    if (!stripe) {
        fprintf(stderr, "Cannot get current set from NULL stripe\n");
        exit(EXIT_FAILURE);
    }

    sllist_set_i(stripe->llist, val);
}

void sstripe_current_pred(sstripe *stripe) {
    if (!stripe) {
        fprintf(stderr, "Cannot get current pred from NULL stripe\n");
        exit(EXIT_FAILURE);
    }

    int old_val = sllist_value_i(stripe->llist);

    sllist_set_i(stripe->llist, old_val - 1);
}

void sstripe_current_succ(sstripe *stripe) {
    if (!stripe) {
        fprintf(stderr, "Cannot get current succ from NULL stripe\n");
        exit(EXIT_FAILURE);
    }

    int old_val = sllist_value_i(stripe->llist);

    sllist_set_i(stripe->llist, old_val + 1);
}

int sstripe_get_index(sstripe *stripe, int n) {
    if (!stripe) {
        fprintf(stderr, "Cannot get index from NULL stripe\n");
        exit(EXIT_FAILURE);
    }

    if (n >= stripe->size) {
        fprintf(stderr, "Cannot get index out of range\n");
        exit(EXIT_FAILURE);
    }

    sllist *llist = stripe->llist;
    llist = sllist_aux_first(llist);

    for (int i = 0; i < n; i++) {
        llist = sllist_next(llist);
    }

    return sllist_value_i(llist);
}

void sstripe_print(sstripe *stripe) {
    sllist *next = sllist_aux_first(stripe->llist);
    while (next != NULL) {
        int val = sllist_value_i(next);
        printf("%d ", val);
        next = sllist_next(next);
    }
    printf("\n");
}
