#ifndef __COMPARE_ARRAY_H
#define __COMPARE_ARRAY_H

#include "../array.h"

typedef int* Int_ptr;
typedef char* Char_ptr;
typedef void* Void_ptr;

typedef void (*Printer)(Void_ptr);

Bool are_values_equal(Void_ptr a, Void_ptr b);
void print_int(Void_ptr number);
void print_array(Void_ptr list, int length, Printer printer_func, Char_ptr message);
void compare_arrayes(Int_ptr actual, Int_ptr expectation, int length);

#endif