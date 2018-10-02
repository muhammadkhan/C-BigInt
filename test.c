/*******************************************************************************
 * C-BigInt (by Muhammad Khan)                                                *
 *                                                                             *
 *                                                                             *
 * An implementation of Big Integers, as inspired by Java, written in the      *
 * C language. Corresponding Makefile will create a static library so this can *
 * be used in other projects. Used when integers of interest might overflow    *
 * and cannot be stored in a traditional C 'int'.                              *
 *******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "bigint.h"

void big_int_init_test(){

  big_int_t bi = big_int_init();
  big_int_print(bi);
  big_int_destroy(bi);
}

void big_int_from_int_test(int n){
  printf("n = %d: ", n);
  big_int_t x = big_int_from_int(n);
  big_int_print(x);
  big_int_destroy(x);
}

void big_int_from_long_long_test(long long n){
  printf("n = %lld: ", n);
  big_int_t x = big_int_from_long_long(n);
  big_int_print(x);
  big_int_destroy(x);
}

void scratchpad(){
  int x = 741;
  printf("\n\n");
  printf("======SCRATCHPAD======\n");
  printf("sizeof(unsigned int) = %lu\n", sizeof(unsigned int));
  printf("sizeof(unsigned long long) = %lu\n", sizeof(unsigned long long));
  printf("741 (1011100101) & 0xff = %u\n", 741 & 0xff);
  printf("741 (1011100101) inverted = %d\n", ~x);
}

void big_int_add_test(){
  big_int_t b1 = big_int_from_int(INT_MAX);
  big_int_t b2 = big_int_from_long_long(LLONG_MAX);
  big_int_t b3 = big_int_from_long_long(LLONG_MAX);
  printf("INT_MAX: ");
  big_int_print(b1);
  printf("\nLLONG_MAX: ");
  big_int_print(b2);
  big_int_add(b1, b3);
  big_int_add(b2, b3);
  printf("\nINT_MAX + LLONG_MAX = ");
  big_int_print(b1);
  printf("\nLLONG_MAX + LLONG_MAX = ");
  big_int_print(b2);
  big_int_add(b2,b3);
  printf("\nLLONG_MAX*3 = ");
  big_int_print(b2);
  printf("\n");
  big_int_destroy(b1);
  big_int_destroy(b2);
  big_int_destroy(b3);
}

int main(){
  //big_int_init_test();
  //big_int_from_int_test(INT_MIN);
  //big_int_from_int_test(INT_MAX);
  //big_int_from_int_test(UINT_MAX);
  //big_int_from_long_long_test(LLONG_MIN);
  //big_int_from_long_long_test(LLONG_MAX);
  //big_int_from_long_long_test(ULLONG_MAX);
  big_int_add_test();
  //scratchpad();
  return 0;
}
