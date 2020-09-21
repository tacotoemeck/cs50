#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

void calculateColemanLiauIndex(float letter_count, float word_count, int sentence_count);
int main(void)
{
    string text = get_string("Text :");
    float letter_count = 0;
    float word_count = 0;
    int sentence_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter_count++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
        else if (text[i] == ' ')
        {
            word_count++;
        }
    }
    word_count++;

    calculateColemanLiauIndex(letter_count, word_count, sentence_count);
}

void calculateColemanLiauIndex(float letter_count, float word_count, int sentence_count)
{
    float lettersAveragePer100words = (letter_count / word_count) * 100;
    float sentencesAveragePer100words = (sentence_count / word_count) * 100;
    int colemanLiauIndex = round(0.0588 * lettersAveragePer100words - 0.296 * sentencesAveragePer100words - 15.8);

    if (colemanLiauIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (colemanLiauIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", colemanLiauIndex);
    }
}
