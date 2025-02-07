#include <stdio.h>
#include "cs50.h"

int main(void){
    string res = get_string("What's your name?");
    printf("hello, %s\n", res);
}
