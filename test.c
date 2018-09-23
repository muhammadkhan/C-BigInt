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

void big_int_init_and_destroy_test(){
  printf("About to Initialize\n");
  big_int_t bi = big_int_init();
  printf("Initialzed!\n");
  printf("Value: ");
  big_int_print(bi);
  printf("\nAbout to Destroy\n");
  big_int_destroy(bi);
  printf("Destroyed!\n");
  printf("Value: ");
  big_int_print(bi);
}

int main(){
  big_int_init_and_destroy_test();
  return 0;
}
