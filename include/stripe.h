#ifndef __STRIPE_H__
#define __STRIPE_H__

// Made to work with int
// Implements stripe like in turing machine
typedef struct stripe sstripe;

sstripe *sstripe_create();
void sstripe_free(sstripe *stripe);

/* Returns current cursor pos of stripe
 */
int sstripe_cursor(sstripe *stripe);

/* Decrements current cursor pos
 */
void sstripe_cursor_previous(sstripe *stripe);

/* Increments current cursor pos
 */
void sstripe_cursor_next(sstripe *stripe);

/* Returns value at cursor pos on stripe
 */
int sstripe_current(sstripe *stripe);

/* Set value at cursor pos on stripe
 */
void sstripe_current_set(sstripe *stripe, int val);

/* Decrements of 1 the value at cursor pos on stripe
 */
void sstripe_current_pred(sstripe *stripe);

/* Increments of 1 the value at cursor pos on stripe
 */
void sstripe_current_succ(sstripe *stripe);

#endif
