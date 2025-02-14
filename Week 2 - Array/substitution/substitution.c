#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substitution_cipher(string text, string key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            int index = text[i] - base;
            text[i] = isupper(text[i]) ? toupper(key[index]) : tolower(key[index]);
        }
    }
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    int letters[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        char lower = tolower(key[i]);
        if (letters[lower - 'a'] > 0)
        {
            return false;
        }

        letters[lower - 'a']++;
    }

    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int count = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isalpha(argv[1][i]))
        {
            count++;
        }
    }

    if (!is_valid_key(argv[1]))
    {
        printf("Key most contain 26 characters\n");
        return 1;
    }

    string str = get_string("plaintext: ");
    substitution_cipher(str, argv[1]);
    printf("ciphertext: %s\n", str);

    return 0;
}
