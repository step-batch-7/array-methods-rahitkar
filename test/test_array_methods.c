#include <stdio.h>
#include <stdlib.h>

#include "test_array_methods.h"

int sqr(int num)
{
  return num * num;
}

void test_map(Array_ptr array)
{
  printf("testing map:\n");
  int expectation[4] = {1, 4, 9, 16};
  Array_ptr actual = map(array, &sqr);
  Bool result = compare_arrayes(actual->array, expectation, 4, sizeof(int) , &are_int_values_equal);
  show_result(actual->array, expectation, actual->length, result, sizeof(int), &print_int);

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
  Array_ptr actual = filter(array, &is_even);
  Bool result = compare_arrayes(actual->array, expectation, 2, sizeof(int), &are_int_values_equal);
  show_result(actual->array, expectation, actual->length, result, sizeof(int), &print_int);

  printf("\n");
}

int sum(int num, int previous_sum)
{
  return num + previous_sum;
}

void test_reduce(Array_ptr array)
{
  printf("testing reduce:\n");
  int expectation = 10;
  int actual = reduce(array, 0, &sum);

  printf("actual: ");
  print_int(&actual);
  printf("\n");
  printf("expectation: ");
  print_int(&expectation);
  printf("\n");

  if (are_int_values_equal(&actual, &expectation))
  {
    printf("✓ values are equal");
    printf("\n");
    return;
  }
  printf("✘ values are not equal");
  printf("\n");
}