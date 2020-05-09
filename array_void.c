#include <stdlib.h>

#include "array_void.h"

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array = malloc(src->length * sizeof(Void_ptr));
  new_array->length = src->length;

  for (int indx = 0; indx < src->length; indx++)
  {
    new_array->array[indx] = (*mapper)(src->array[indx]);
    // printf("%d ", *(int*)new_array->array[indx]);
  }
  return new_array;
}
