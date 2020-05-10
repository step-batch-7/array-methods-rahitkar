#include <stdio.h>
#include <stdlib.h>

#include "../array_void.h"
#include "compare_array.h"
#include "test_array_methods.h"
#include "test_void_array_methods.h"

int main(void)
{
  int int_array[4] = {1, 2, 3, 4};
  Array_ptr array = malloc(sizeof(Array));
  array->array = int_array;
  array->length = 4;

  test_map(array);
  test_filter(array);
  test_reduce(array);

  printf("\n");

  ArrayVoid_ptr array_void = malloc(sizeof(ArrayVoid));
  array_void->array = create_void_array(int_array, 4, 4);
  array_void->length = 4;

  test_void_map(array_void);
  test_void_filter(array_void);
}