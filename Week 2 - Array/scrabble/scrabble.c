#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word)
{
    int score = 0;

    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}

int main(void)
{

    // get words
    string word1 = get_string("Player 1: Question?\n");
    string word2 = get_string("Player 2: Question?\n");
    // compute score
    int score_1 = compute_score(word1);
    int score_2 = compute_score(word2);
    // print the wins
    if (score_1 > score_2)
        printf("Player 1 wins!\n");
    else if (score_1 < score_2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");

    return 0;
}
