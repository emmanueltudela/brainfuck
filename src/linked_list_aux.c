#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

sllist *sllist_aux_first(sllist *llist) {
    if (!llist) {
        fprintf(stderr, "Cannot get first from NULL llist\n");
        exit(EXIT_FAILURE);
    }

    sllist *first = llist;

    while (sllist_previous(first) != NULL) {
        first = sllist_previous(first);
    }

    return first;
}

sllist *sllist_aux_last(sllist *llist) {
    if (!llist) {
        fprintf(stderr, "Cannot get last from NULL llist\n");
        exit(EXIT_FAILURE);
    }

    sllist *last = llist;

    while (sllist_next(last) != NULL) {
        last = sllist_next(last);
    }

    return last;
}

sllist *sllist_aux_append(sllist *llist, char val) {
    if (!llist) return sllist_append(llist, val);

    sllist *last = sllist_aux_last(llist);
    sllist_append(last, val);
    return llist;
}

sllist *sllist_aux_prepend(sllist *llist, char val) {
    if (!llist) return sllist_prepend(llist, val);

    sllist *first = sllist_aux_first(llist);
    sllist_prepend(first, val);
    return llist;
}

sllist *sllist_aux_remove_all(sllist *llist) {
    if (!llist) return NULL;

    llist = sllist_aux_first(llist);

    while (llist != NULL) {
        llist = sllist_remove(llist);
    }

    return NULL;
}
