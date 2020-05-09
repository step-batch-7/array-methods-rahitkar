#include <stdlib.h>

#include "array_void.h"

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array = malloc(src->length * sizeof(Object));
  new_array->length = src->length;

  for (int indx = 0; indx < src->length; indx++)
  {
    new_array->array[indx] = (*mapper)(src->array[indx]);
  }
  return new_array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array = malloc(src->length * sizeof(Object));
  new_array->length = 0;

  for (int indx = 0; indx < src->length; indx++)
  {
    if ((*predicate)(src->array[indx]) == 1)
    {
      new_array->array[new_array->length] = src->array[indx];
      new_array->length++;
    }
  }
  return new_array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int indx = 0; indx < src->length; indx++)
  {
    init = reducer(src->array[indx], init);
  }
  return init;
}
