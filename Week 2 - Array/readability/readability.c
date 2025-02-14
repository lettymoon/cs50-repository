#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(const char text[])
{
    int count = 0;
    int in_word = 0;
    int i = 0;

    while (text[i] != '\0')
    {
        if (isspace((unsigned char) text[i]))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        i++;
    }

    return count;
}

int count_sentences(const char text[])
{
    int count = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
        i++;
    }
    return count;
}

int count_letters(const char text[])
{
    int count = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (isalpha((unsigned char) text[i]))
        {
            count++;
        }
        i++;
    }
    return count;
}

float compute_coleman_liau(const char text[])
{
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    return index;
}

int main()
{

    // get text
    string text = get_string("Text: ");
    text[strcspn(text, "\n")] = 0;

    // count words, letters and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // compute Coleman-Liau
    float asw = compute_coleman_liau(text);

    if (asw < 1)
        printf("Before Grade 1\n");
    else if (asw > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %.0f\n", round(asw));

    return 0;
}
