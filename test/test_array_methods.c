#include <stdio.h>
#include <stdlib.h>

#include "../array.h"

typedef void (*Printer)(Void_ptr);

int sqr(int num)
{
  return num * num;
}

Bool are_values_equal(Void_ptr a, Void_ptr b)
{
  return *(Int_ptr)a == *(Int_ptr)b;
}

void print_int(Void_ptr number)
{
  printf("%d ", *(int *)number);
}

void print_array(Void_ptr list, int length, Printer printer_func, Char_ptr message)
{
  printf("%s: [ ", message);
  for (int indx = 0; indx < length; indx++)
  {
    (*printer_func)(list + indx * sizeof(int));
  }
  printf("]\n");
}

void compare_arrayes(Int_ptr actual, Int_ptr expectation, int length)
{
  for (int i = 0; i < length; i++)
  {
    if (!are_values_equal(&actual[i], &expectation[i]))
    {
      print_array(actual, length, &print_int, "actual");
      print_array(expectation, length, &print_int, "expectation");
      printf("✘ both array values are not same\n");
      return;
    }
  }
  print_array(actual, length, &print_int, "actual");
  print_array(expectation, length, &print_int, "expectation");
  printf("✓ both array values are equal\n");
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