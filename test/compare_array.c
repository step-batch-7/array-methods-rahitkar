#include <stdio.h>

#include "compare_array.h"

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