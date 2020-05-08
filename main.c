#include <stdio.h>
#include <stdlib.h>

#include "array.h"

typedef void (*Printer)(void *);

int sqr(int num)
{
  return num * num;
}

int cube(int num)
{
  return sqr(num) * num;
}

Bool is_even(int num)
{
  return !(num % 2);
}

int sum(int num, int previous_sum)
{
  return num + previous_sum;
}

void print_int(void *number)
{
  printf("%d ", *(int *)number);
}

void print_list(int *list, int length, Printer printer_func)
{
  printf("[ ");
  for (int indx = 0; indx < length; indx++)
  {
    (*printer_func)(list + indx);
  }
  printf("]\n");
}

int main(void)
{
  int int_array[4] = {1, 2, 3, 4};
  Array_ptr array = malloc(sizeof(Array));
  array->array = int_array;
  array->length = 4;

  Array_ptr new_array = map(array, &sqr);
  print_list(new_array->array, new_array->length, &print_int);

  new_array = filter(array, &is_even);
  print_list(new_array->array, new_array->length, &print_int);

  int result = reduce(array, 0, &sum);
  print_int(&result);
  printf("\n");

  return 0;
}