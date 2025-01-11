#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdbool.h>

#include "type_val.h"

typedef struct llist sllist;

// Empty sllist is NULL
sllist *sllist_create();
void sllist_free(sllist *llist);

bool sllist_empty(sllist *llist);

sllist *sllist_previous(sllist *llist);
sllist *sllist_next(sllist *llist);

sllist *sllist_append(sllist *llist, stype_val val);
sllist *sllist_prepend(sllist *llist, stype_val val);

sllist *sllist_append_i(sllist *llist, int val);
sllist *sllist_prepend_i(sllist *llist, int val);
sllist *sllist_append_c(sllist *llist, char val);
sllist *sllist_prepend_c(sllist *llist, char val);

stype_val sllist_value(sllist *llist);

int sllist_value_i(sllist *llist);
char sllist_value_c(sllist *llist);

sllist *sllist_remove(sllist *llist);

#endif
