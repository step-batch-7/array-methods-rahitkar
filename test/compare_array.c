#include <stdio.h>

#include "compare_array.h"

Bool are_int_values_equal(Void_ptr num1, Void_ptr num2)
{
  return *(Int_ptr)num1 == *(Int_ptr)num2;
}

void print_int(Void_ptr number)
{
  printf("%d ", *(Int_ptr)number);
}

void print_array(Void_ptr list, int length, Char_ptr message, Printer printer_func)
{
  printf("%s: [ ", message);
  for (int indx = 0; indx < length; indx++)
  {
    (*printer_func)(list + indx * sizeof(int));
  }
  printf("]\n");
}

Bool compare_arrayes(Void_ptr actual, Void_ptr expectation, int length, Compare check_equality)
{
  Void_ptr actual_ref; 
  Void_ptr expectation_ref;
  for (int i = 0; i < length; i++)
  {
    actual_ref = (actual + (i * sizeof(int)));
    expectation_ref = (expectation + (i * sizeof(int)));
    if (!(*check_equality)(actual_ref, expectation_ref))
    {
      return 0;
    }
  }
  return 1;
}

void show_result(Void_ptr actual, Void_ptr expectation, int length, Bool result,Printer print)
{
  print_array(actual, length, "actual", print);
  print_array(expectation, length, "expectation", print);

  if (!result)
  {
  printf("✘ both array values are not same\n");
  return;
  }
  printf("✓ both array values are equal\n");
}