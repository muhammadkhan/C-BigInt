/*******************************************************************************
 * C-BigInt (by Muhammad Khan)                                                *
 *                                                                             *
 *                                                                             *
 * An implementation of Big Integers, as inspired by Java, written in the      *
 * C language. Corresponding Makefile will create a static library so this can *
 * be used in other projects. Used when integers of interest might overflow    *
 * and cannot be stored in a traditional C 'int'.                              *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

struct big_int {
  unsigned int* number;
  unsigned int len;
};

big_int_t big_int_init(){
  big_int_t bi = malloc(sizeof(*bi));
  bi->number = malloc(sizeof(*(bi->number)));
  bi->number[0] = 0;
  bi->len = 1;
  return bi;
}

void big_int_destroy(big_int_t bi){
  free(bi->number);
  free(bi);
}

void big_int_add(big_int_t a, big_int_t b){
  unsigned int new_len;
  struct big_int bigger, smaller;
  if(a->len > b->len){
    bigger = *a;
    smaller = *b;
    new_len = a->len;
  } else{
    bigger = *b;
    smaller = *a;
    new_len = b->len;
  }
  unsigned int new_num[new_len];
  int gap = bigger.len - smaller.len;
  unsigned int carry = 0;
  for(int i = new_len - 1; i >= 0; i--){
    int b_index = i, s_index = i-gap;
    unsigned int temp = carry + bigger.number[b_index] + ((s_index >= 0) ? smaller.number[s_index] : 0);
    new_num[b_index] = temp % 10;
    carry = temp / 10;
  }
  int l = (carry > 0) ? 1+new_len : new_len;
  unsigned int* num = malloc(l*sizeof(*num));
  if(carry > 0){
    num[0] = carry;
    for(int i = 0; i < new_len; i++)
      num[i+1] = new_num[i];
  } else
    num = new_num;

  free(a->number);
  a->number = num;
  a->len = l;
}

void big_int_subtract(big_int_t a, big_int_t b){

}

void big_int_print(big_int_t bi){
  if(bi == NULL){
    printf("NULL\n");
  }
  for(int i = 0; i < bi->len; i++)
    printf("%d", bi->number[i]);
  printf("\n");
}