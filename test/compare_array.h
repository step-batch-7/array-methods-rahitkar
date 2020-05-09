#ifndef __COMPARE_ARRAY_H
#define __COMPARE_ARRAY_H

#include "../array.h"

typedef int* Int_ptr;
typedef char* Char_ptr;
typedef void* Void_ptr;

typedef void (*Printer)(Void_ptr);
typedef Bool(*Compare)(Void_ptr, Void_ptr);

Bool are_int_values_equal(Void_ptr a, Void_ptr b);
void print_int(Void_ptr number);
void print_array(Void_ptr list, int length, Char_ptr message, Printer printer_func);
Bool compare_arrayes(Void_ptr actual, Void_ptr expectation, int length, Compare check_equality);
void show_result(Void_ptr actual, Void_ptr expectation, int length, Bool result,Printer print);
#endif