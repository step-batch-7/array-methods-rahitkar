#ifndef __COMPARE_VOID_ARRAY_H
#define __COMPARE_VOID_ARRAY_H

#include "../array_void.h"
#include "compare_array.h"

void print_void_array(ArrayVoid_ptr src, Char_ptr message, Printer print);
Bool compare_void_arrayes(ArrayVoid_ptr actual, ArrayVoid_ptr expected, Compare check_equality);
void show_result_for_void_array(ArrayVoid_ptr actual, ArrayVoid_ptr expected, Bool result, Printer print);
#endif