/*******************************************************************************
 * C-BigInt (by Muhammad Khan)                                                *
 *                                                                             *
 *                                                                             *
 * An implementation of Big Integers, as inspired by Java, written in the      *
 * C language. Corresponding Makefile will create a static library so this can *
 * be used in other projects. Used when integers of interest might overflow    *
 * and cannot be stored in a traditional C 'int'.                              *
 *******************************************************************************/

#ifndef BIGINT_H_
#define BIGINT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct big_int* big_int_t;

/**
 * Initializes a big integer set to a 0 value.
 */
big_int_t big_int_init();

/**
 * Destroys the given big integer.
 */
void big_int_destroy(big_int_t bi);
/**
 * Adds 'a' and 'b' and stores the value in 'a'.
 */
void big_int_add(big_int_t a, big_int_t b);


/**
 * Subtracts 'b' from 'a', and updates the value in 'a'.
 * Requires: a > b
 */
void big_int_subtract(big_int_t a, big_int_t b);

void big_int_print(big_int_t bi);

#ifdef __cplusplus
}
#endif

#endif /* BIGINT_H_ */
