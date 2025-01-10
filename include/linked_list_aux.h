#ifndef __LINKED_LIST_AUX_H__
#define __LINKED_LIST_AUX_H__

#include "linked_list.h"

// Made to work with char for brainfuck

sllist *sllist_aux_first(sllist *llist);
sllist *sllist_aux_last(sllist *llist);

sllist *sllist_aux_append(sllist *llist, char val);
sllist *sllist_aux_prepend(sllist *llist, char val);

sllist *sllist_aux_remove_all(sllist *llist);

#endif
