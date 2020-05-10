#ifndef __TEST_ARRAY_METHODS_H
#define __TEST_ARRAY_METHODS_H

#include "../array.h"
#include "compare_array.h"

int sqr(int num);
void test_map(Array_ptr array);
Bool is_even(int num);
void test_filter(Array_ptr array);
int sum(int num, int previous_sum);
void test_reduce(Array_ptr array);

#endif