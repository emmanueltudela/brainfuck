#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdbool.h>

typedef struct llist sllist;

// Value is NULL
sllist *sllist_create();
void sllist_free(sllist *llist);

#endif
