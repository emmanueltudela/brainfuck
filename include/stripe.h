#ifndef __STRIPE_H__
#define __STRIPE_H__

// Made to work with int
typedef struct stripe sstripe;

sstripe *sstripe_create();
void sstripe_free(sstripe *stripe);

int sstripe_cursor(sstripe *stripe);
void sstripe_cursor_previous(sstripe *stripe);
void sstripe_cursor_next(sstripe *stripe);

int sstripe_current(sstripe *stripe);
void sstripe_current_pred(sstripe *stripe);
void sstripe_current_succ(sstripe *stripe);

#endif
