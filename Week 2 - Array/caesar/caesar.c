#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void caesar_cipher(char *str, int k){

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if(isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            str[i] = (c - base + k) % 26 + base;
        }
    }
}

int main(int argc, char *argv[]){
     if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    int k = atoi(argv[1]);

    string str = get_string("plaintext: ");
    caesar_cipher(str, k);
    printf("ciphertext: %s\n", str);

    return 0;
}
