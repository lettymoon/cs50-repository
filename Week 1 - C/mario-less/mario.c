#include <stdio.h>
#include "cs50.h"

void print_row(int spaces, int bricks){
    for (int i = 1; i <= spaces; i++){
        printf(" ");
    }

    for (int i = 1; i <= bricks; i++){
        printf("#");
    }
}

int main(void){

    int n;
    do{
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int i = 1; i <= n; i++){

        print_row(n-i, i);
        printf("\n");
    }

    return 0;
}



