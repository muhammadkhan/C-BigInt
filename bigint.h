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
   * @brief      Creates a big integer from the given integer
   *
   * @details    big_int_from_int(n) takes in a (signed) integer and creates the
   *             big_int wrapper around it so that it may be treated as a big_int.
   *
   * @param      [n] a signed integer which is to be converted
   *
   * @return     A (dynamically allocated) big integer whose value is the input number
   */
  big_int_t big_int_from_int(int n);

  /**
   * @brief      Creates a big integer from the given long long integer
   *
   * @details    big_int_from_long_long(n) takes in a (signed) long long integer and
   *             creates the big_int wrapper around it so that it may be treated as
   *             a big_int
   *
   * @param      [n] a signed long long integer which is to be converted
   *
   * @return     A (dynamically allocated) big integer whose value is the input number
   */
  big_int_t big_int_from_long_long(long long n);

  /**
   * @brief      Converts the given big_int into a (signed) long long
   *
   * @details    big_int_to_long_long(bi) will take the given big_int and return
   *             it to the standard long long int.
   *
   * @param      [bi] The big_int to be converted into long long
   *
   * @return     A long long with the same value as bi->number
   */
  long long big_int_to_long_long(big_int_t bi);


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

  /**
   * @brief      function description
   *
   * @details    detailed description
   *
   * @param      param
   *
   * @return     return type
   */
  void big_int_incr(big_int_t bi, const unsigned int val);

  void big_int_decr(big_int_t bi, const unsigned int val);

  void big_int_print(big_int_t bi);

#ifdef __cplusplus
}
#endif

#endif /* BIGINT_H_ */
