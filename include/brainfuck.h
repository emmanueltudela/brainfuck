#ifndef __BRAINFUCK_H__
#define __BRAINFUCK_H__

#include <stdbool.h>

typedef struct brainfuck sbrainfuck;

sbrainfuck *sbrainfuck_create();
void sbrainfuck_free(sbrainfuck *bf);

/* Interprets a char or a list of char (string) in the given brainfuck
 * execution environment
 */
void sbrainfuck_load_char(sbrainfuck *bf, char c);
void sbrainfuck_load_string(sbrainfuck *bf, char *c);

bool sbrainfuck_finished(sbrainfuck *bf);

void sbrainfuck_iter(sbrainfuck *bf);

/* Iterate the loaded brainfuck until it's finished
 */
void sbrainfuck_compute(sbrainfuck *bf);

/* Returns the value on brainfuck stripe at index n
 */
int sbrainfuck_get_index(sbrainfuck *bf, int n);
void sbrainfuck_print(sbrainfuck *bf);

#endif
