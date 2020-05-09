#include <stdio.h>
#include <stdlib.h>

#include "array_void.h"

typedef int *Int_ptr;
typedef void (*Printer)(void *);

Object int_sqr(Object num)
{
  Int_ptr result = malloc(sizeof(int));
  *result = (*(Int_ptr)num * *(Int_ptr)num);
  return result;
}

Bool is_even(Object num)
{
  return !(*(Int_ptr)num % 2);
}

Object int_sum(Object num, Object cotext)
{
  Int_ptr result = malloc(sizeof(int));
  *result = *(Int_ptr)num + *(Int_ptr)cotext;
  return result;
}

void print_int(void *number)
{
  printf("%d ", *(int *)number);
}

void print_void_array(ArrayVoid_ptr src, Printer print)
{
  printf("[ ");

  for (int indx = 0; indx < src->length; indx++)
  {
    (*print)(src->array[indx]);
  }
  printf("]\n");
}

int main(void)
{
  int *num1 = malloc(sizeof(int));
  *num1 = 1;

  int *num2 = malloc(sizeof(int));
  *num2 = 2;

  int *num3 = malloc(sizeof(int));
  *num3 = 3;

  int *num4 = malloc(sizeof(int));
  *num4 = 4;

  int *numbers[4] = {num1, num2, num3, num4};

  ArrayVoid_ptr array_void = malloc(sizeof(ArrayVoid));
  array_void->array = (Object *)&numbers[0];
  array_void->length = 4;

  ArrayVoid_ptr mapped_void_array = map_void(array_void, &int_sqr);
  print_void_array(mapped_void_array, &print_int);

  ArrayVoid_ptr filtered_void_array = filter_void(array_void, &is_even);
  print_void_array(filtered_void_array, &print_int);

  int* init = malloc(sizeof(int));
  *init = 0;
  Object result = reduce_void(array_void, init,&int_sum);
  print_int(result);
  printf("\n");

  return 0;
}