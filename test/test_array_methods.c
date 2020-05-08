#include <stdlib.h>

#include "../array.h"
#include "compare_array.h"

int sqr(int num)
{
  return num * num;
}

void test_map(Array_ptr array)
{
  int expectation[4] = {1, 4, 9, 16};
  Array_ptr new_array = map(array, &sqr);
  compare_arrayes(new_array->array, expectation, 4);
}

int main(void)
{
  int int_array[4] = {1, 2, 3, 4};
  Array_ptr array = malloc(sizeof(Array));
  array->array = int_array;
  array->length = 4;

  test_map(array);
}