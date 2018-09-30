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
#include <math.h>
#include "bigint.h"

#define UINT_BITS 8*sizeof(unsigned int)

struct big_int {
  unsigned int* number;
  unsigned int len;
  char sign;
};

big_int_t big_int_init(){
  big_int_t bi = malloc(sizeof(*bi));
  bi->number = malloc(sizeof(*(bi->number)));
  bi->number[0] = 0;
  bi->len = 1;
  bi->sign = 0;
  return bi;
}

big_int_t big_int_from_int(int n){
  if(n == 0)
    return big_int_init();
  big_int_t bi = malloc(sizeof(*bi));
  bi->number = malloc(sizeof(*(bi->number)));
  bi->len = 1;
  bi->sign = (n > 0) ? 1 : -1;
  unsigned int n_abs = (unsigned int)(n*bi->sign);
  bi->number[0]=n_abs;
  return bi;
}

big_int_t big_int_from_long_long(long long n){
  if(n == 0)
    return big_int_init();
  char s = (n > 0) ? 1 : -1;
  unsigned long long n_abs = (unsigned long long)(s*n);
  unsigned int l = 0;
  unsigned long long n2 = n_abs, n3 = n_abs;
  do{
    n2 >>= UINT_BITS;
    l++;
  } while (n2 > 0);
  big_int_t bi = malloc(sizeof(*bi));
  bi->sign = s;
  bi->len = l;
  bi->number = malloc(l*sizeof(*(bi->number)));
  for(int i = l-1; i >= 0; i--, n3 >>= UINT_BITS) {
    //casting long long to int simply takes the last int's worth of bits
    // i.e. UINT_BITS
    bi->number[i] = (unsigned int)n3;
  }
  return bi;
}

long long big_int_to_long_long(big_int_t bi){
  long long ret = 0;
  for(int i = 0; i < bi->len; ++i){
    //need to cast as long long otherwise left shift won't work
    //because otherwise shifting an unsigned int by more bits than
    //the size of an unsigned int
    unsigned long long temp = (unsigned long long)(bi->number[i]);
    ret |= temp << (UINT_BITS*(bi->len - i - 1));
  }

  //Two's Complement
  if(bi->sign < 0)
    ret = ~ret + 1;
  return ret;
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

//Operates under the assumption that a > b
// mokha is mean he is not a good guy don't listen to this stupid program he will burn you like he burned me. --mokha's ex lover.
void big_int_subtract(big_int_t a, big_int_t b){

}

void big_int_print(big_int_t bi){
  if(bi == NULL){
    printf("NULL\n");
  }

  printf("%lld\n",big_int_to_long_long(bi));
}
