#include <stdio.h>
#include <stdlib.h>

#include "../array.h"
#include "compare_array.h"


int sqr(int num)
{
  return num * num;
}

void test_map(Array_ptr array)
{
  printf("testing map:\n");
  int expectation[4] = {1, 4, 9, 16};
  Array_ptr new_array = map(array, &sqr);
  compare_arrayes(new_array->array, expectation, 4);
  printf("\n");
}

Bool is_even(int num)
{
  return !(num % 2);
}

void test_filter(Array_ptr array)
{
  printf("testing filter:\n");
  int expectation[4] = {2, 4};
  Array_ptr new_array = filter(array, &is_even);
  compare_arrayes(new_array->array, expectation, 2);
  printf("\n");
}

int main(void)
{
  int int_array[4] = {1, 2, 3, 4};
  Array_ptr array = malloc(sizeof(Array));
  array->array = int_array;
  array->length = 4;

  test_map(array);
  test_filter(array);
}