#ifndef __ARRAY_H
#define __ARRAY_H
typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int* array;
  int length;
} Array;

typedef Array* Array_ptr;

Array_ptr map(Array *src, Mapper mapper);
Array_ptr filter(Array *src, Predicate predicate);
int reduce(Array *src, int init, Reducer reducer);

#endif
