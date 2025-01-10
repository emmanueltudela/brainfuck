#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdbool.h>

// Made to work with char for brainfuck
typedef struct llist sllist;

// Empty sllist is NULL
sllist *sllist_create();
void sllist_free(sllist *llist);

bool sllist_empty(sllist *llist);

sllist *sllist_append(sllist *llist, char val);
sllist *sllist_prepend(sllist *llist, char val);

char sllist_value(sllist *llist);

sllist *sllist_remove(sllist *llist);

#endif
