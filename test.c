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
#include "bigint.h"

void big_int_init_test(){

  big_int_t bi = big_int_init();
  big_int_print(bi);
  big_int_destroy(bi);
}

void big_int_from_num_test(int n){
  printf("n = %d: ", n);
  big_int_t x = big_int_from_num(n);
  big_int_print(x);
  big_int_destroy(x);
}

int main(){
  big_int_init_test();
  big_int_from_num_test(3);
  big_int_from_num_test(45);
  big_int_from_num_test(843);
  big_int_from_num_test(3543);
  return 0;
}
