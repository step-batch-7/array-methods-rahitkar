#include <stdio.h>
#include <stdlib.h>

#include "../array_void.h"
#include "compare_array.h"
#include "compare_void_array.h"
#include "test_void_array_methods.h"

typedef int *Int_ptr;
typedef void (*Printer)(void *);

Object create_void_array(Object array, int length, int element_size)
{
  Object* new_array = malloc(sizeof(Object) * length);

  for(int indx = 0; indx < length; indx++)
  {
    new_array[indx] = array + (indx * element_size);
  }
  return new_array;
}

Object void_int_sqr(Object num)
{
  Int_ptr result = malloc(sizeof(int));
  *result = (*(Int_ptr)num * *(Int_ptr)num);
  return result;
}

void test_void_map(ArrayVoid_ptr array_void)
{
printf("testing map_void:\n");
  int expectation[4] = {1, 4, 9, 16};
  ArrayVoid_ptr expectation_void = malloc(sizeof(ArrayVoid));
  expectation_void->array = create_void_array(expectation, 4, 4);
  expectation_void->length = 4;

  ArrayVoid_ptr actual_void = map_void(array_void, &void_int_sqr);

  Bool result = compare_void_arrayes(actual_void, expectation_void, &are_int_values_equal);
  show_result_for_void_array(actual_void, expectation_void, result, &print_int);

  printf("\n");
}

Bool void_is_even(Object num)
{
  return !(*(Int_ptr)num % 2);
}

void test_void_filter(ArrayVoid_ptr array_void)
{
printf("testing filter_void:\n");
  int expectation[2] = {2, 4};
  ArrayVoid_ptr expectation_void = malloc(sizeof(ArrayVoid));
  expectation_void->array = create_void_array(expectation, 2, 4);
  expectation_void->length = 2;

  ArrayVoid_ptr actual_void = filter_void(array_void, &void_is_even);

  Bool result = compare_void_arrayes(actual_void, expectation_void, &are_int_values_equal);
  show_result_for_void_array(actual_void, expectation_void, result, &print_int);

  printf("\n");
}
