#include <iostream>
#include <cstdio>
#include <cstdarg>

bool debug = false;

void debugOut(const char* str, ...){
    va_list ap;
    if(debug){
        va_start(ap, str);
        vfprintf(stderr, str, ap);
        va_end(ap);
    }
}
int main(void){
    printf("int %d\n", 5);
    printf("String %s and int %d\n", "hello", 5);
    printf("Many ints: %d, %d, %d, %d, %d\n", 1, 2, 3, 4, 5);
}