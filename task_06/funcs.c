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

int check_brackets(const char *str){
    size_t size = 32, index = 0;
    char *brackets = (char*)malloc(sizeof(char)*size);
    const char *ptr = str;
    char openBrackets[5] = "([{<";
    char closeBrackets[5] = ")]}>";
    while(*ptr != '\0'){
        if(strchr(openBrackets, *ptr) != NULL){
            if(index >= size){
                if(resize(&brackets, &size) != SUCCESS){return REALLOC_FAULT;}
            }
            brackets[index++] = *ptr;
        }else if(strchr(closeBrackets, *ptr) != NULL){
            if(*ptr == ')' && brackets[index-1] == '('){
                brackets[--index] = '\0';
            }else if(*ptr == ']' && brackets[index-1] == '['){
                brackets[--index] = '\0';
            }else if(*ptr == '}' && brackets[index-1] == '{'){
                brackets[--index] = '\0';
            }else if(*ptr == '>' && brackets[index-1] == '<'){
                brackets[--index] = '\0';
            }else{
                return INCORRECT_BRACKET;
            }
        }
        ++ptr;
    }
    free(brackets);
    return (index == 0) ? SUCCESS : INCORRECT_BRACKET;
}

void test_func(){
    char str1[128] = "({23123{423[<321343223>]}241421})41241";
    char str2[128] = "{{[world!!!!!][hello]}";
    char str3[128] = "[(sfnangagnaef)]garga<rgargafaecaewfae>?????wfa}";

    printf("Test first string\n");
    printf("String: %s | balanced: %s\n", str1, (check_brackets(str1) == SUCCESS) ? "Yes" : "No");
    printf("---------------------\n");
    
    printf("Test second string\n");
    printf("String: %s | balanced: %s\n", str2, (check_brackets(str2) == SUCCESS) ? "Yes" : "No");
    printf("---------------------\n");

    printf("Test third string\n");
    printf("String: %s | balanced: %s\n", str3, (check_brackets(str3) == SUCCESS) ? "Yes" : "No");
}