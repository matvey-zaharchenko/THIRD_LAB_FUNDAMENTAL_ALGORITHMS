#ifndef FUNCS_HPP_
#define FUNCS_HPP_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

enum ERRORS{
    SUCCESS,
    MALLOC_FAULT,
    REALLOC_FAULT
};

int resize(char** array, size_t *size);
int fromDecimalToAnother(int number, unsigned r, char **result);
int print_array(int *array, size_t size, unsigned int r);
int test_my_func();

#endif 