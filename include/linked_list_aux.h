#ifndef __LINKED_LIST_AUX_H__
#define __LINKED_LIST_AUX_H__

#include "linked_list.h"
#include "type_val.h"

sllist *sllist_aux_first(sllist *llist);
sllist *sllist_aux_last(sllist *llist);

sllist *sllist_aux_append(sllist *llist, stype_val val);
sllist *sllist_aux_prepend(sllist *llist, stype_val val);

sllist *sllist_aux_append_i(sllist *llist, int val);
sllist *sllist_aux_prepend_i(sllist *llist, int val);
sllist *sllist_aux_append_c(sllist *llist, char val);
sllist *sllist_aux_prepend_c(sllist *llist, char val);

sllist *sllist_aux_remove_all(sllist *llist);

#endif
