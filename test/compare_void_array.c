#include <stdio.h>

#include "compare_void_array.h"
#include "compare_array.h"

void print_void_array(ArrayVoid_ptr src, char* message, Printer print)
{
  printf("%s: [ ", message);

  for (int indx = 0; indx < src->length; indx++)
  {
    (*print)(src->array[indx]);
  }
  printf("]\n");
}

Bool compare_void_arrayes(ArrayVoid_ptr actual, ArrayVoid_ptr expected, Compare check_equality)
{
  if (actual->length != expected->length)
  {
    return 0;
  }

  for (int indx = 0; indx < actual->length; indx++)
  {
    if (!(*check_equality)(actual->array[indx], expected->array[indx]))
    {
      return 0;
    }
  }
  return 1;
}

void show_result_for_void_array(ArrayVoid_ptr actual, ArrayVoid_ptr expected, Bool result, Printer print)
{
  print_void_array(actual, "actual", print);
  print_void_array(expected, "expected", print);
  if (!result)
  {
    printf("✘ both array values are not same\n");
    return;
  }
  printf("✓ both array values are equal\n");
}