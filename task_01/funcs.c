#include "funcs.h"

int resize(char** array, size_t *size){
    *size *= 2;
    char *temp = (char*)realloc(*array, sizeof(char) * (*size));
    if(temp == NULL){
        free(*array);
        return REALLOC_FAULT;
    }
    *array = temp;
    return SUCCESS;
}

int fromDecimalToAnother(int number, unsigned int r, char **result){
    
    size_t size = 50, index = 0, i = 0, pos = 1;
    *result = (char*)malloc(sizeof(char)*size);
    if(*result == NULL){return MALLOC_FAULT;}

    if(number < 0){
        (*result)[index++] = '-';
        number *= -1;
        i = 1; pos = 0;
    }
    
    unsigned int cpy_number = (unsigned int)number;
    unsigned int remainder, multi, div;
    do{
        if(index >= size){
            if(resize(result, &size) != SUCCESS){return REALLOC_FAULT;}
        }

        div = cpy_number >> r;
        multi = div << r;
        remainder = (cpy_number & (~multi));
        
        if(remainder > 9){
            (*result)[index++] = (char)(remainder + 7 + '0'); 
        }else{
            (*result)[index++] = (char)(remainder + '0');
        }
        
        cpy_number = div;
    }while(cpy_number != 0);
    
    if(index >= size){
        if(resize(result, &size) != SUCCESS){return REALLOC_FAULT;}
    }
    (*result)[index] = '\0';
    for( ; i < index / 2; ++i){
        char chr = (*result)[i];
        (*result)[i] = (*result)[index - i - pos];
        (*result)[index - i - pos] = chr; 
    }
    return SUCCESS;
}

int print_array(int *array, size_t size, unsigned int r){
    printf("Test for r = %u | Base = %d\n", r, (int)pow(2, r));
    char *res;
    int status;
    for(int i = 0; i < size; ++i){
        if((status = fromDecimalToAnother(array[i], r, &res)) != SUCCESS){return status;}
        printf("Number %d is %s\n", array[i], res);
        free(res);
    }
    printf("---------------------\n");
    return SUCCESS;
}

int test_my_func(){
    int status;
    int array[10] = {0, 2, -15, 37, -59, 2341, 79, 31, 123425232, 10};

    if((status = print_array(array, 10, 1)) != SUCCESS) {return status;}
    if((status = print_array(array, 10, 2)) != SUCCESS) {return status;}
    if((status = print_array(array, 10, 3)) != SUCCESS) {return status;}
    if((status = print_array(array, 10, 4)) != SUCCESS) {return status;}
    if((status = print_array(array, 10, 5)) != SUCCESS) {return status;}
    
    return SUCCESS;
}