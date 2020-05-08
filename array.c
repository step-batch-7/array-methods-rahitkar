#include <stdlib.h>

#include "array.h"

Array_ptr map(Array_ptr array, Mapper mapper)
{
  Array_ptr new_array = malloc(sizeof(Array));
  new_array->array = malloc(sizeof(int) * array->length);
  new_array->length = array->length;

  for (int indx = 0; indx < array->length; indx++)
  {
    new_array->array[indx] = mapper((array->array[indx]));
  }
  return new_array;
}

Array_ptr filter(Array_ptr array, Predicate predicate)
{
  int element_counter = 0;
  Array_ptr new_array = malloc(sizeof(Array));
  new_array->array = malloc(sizeof(int) * array->length);
  
  for (int indx = 0; indx < array->length; indx++)
  {
    if(predicate(array->array[indx]) == 1)
    {
      new_array->array[element_counter] = array->array[indx];
      element_counter++;
    }
  }
  new_array->length = element_counter;
  return new_array;
}

int reduce(Array_ptr array, int context,  Reducer reducer)
{
  for (int indx = 0; indx < array->length; indx++)
  {
    context = reducer(array->array[indx], context);
  }
  return context;
}