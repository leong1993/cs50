#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int *countText(string word, int *array);


int main(void)
{
    int array[10];
    string text = get_string("Text: ");
    countText(text, array);
    float letter = array[0];
    float words = array[1];
    float sentance = array[2];
    int index = round((0.0588 * (letter / words * 100)) - (0.296 * (sentance / words * 100)) - 15.8);
    // printf("letter %i\n", array[0]);
    // printf("space %i\n", array[1]);
    // printf("sentance %i\n", array[2]);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int *countText(string word, int *array)
{
    int letter = 0, space = 0, sentence = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            letter ++; //letter count
        }
        else if (isspace(word[i]))
        {
            space++; //space count
        }
        else if ((word[i] == '!') || (word[i] == '?') || (word[i] == '.'))
        {
            sentence++;//sentence count
        }

    }
    array[0] = letter;
    array[1] = space + 1; // +1 for the last word
    array[2] = sentence;
    return array;

}