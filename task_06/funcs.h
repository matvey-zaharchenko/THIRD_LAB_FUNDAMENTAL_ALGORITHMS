#ifndef FUNCS_HPP_
#define FUNCS_HPP_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum ERRORS{
    SUCCESS,
    MALLOC_FAULT,
    REALLOC_FAULT,
    INCORRECT_BRACKET
};

int resize(char** array, size_t *size);
int check_brackets(const char *str);
void test_func();

#endif 