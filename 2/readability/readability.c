#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string sentence);
int count_words(string text);
int count_sentences(string text);
int calculate_readability_index(double letters, double words, double sentences);

int main(void)
{

    // Get text
    string input_text = get_string("Text: ");

    int letters_count = count_letters(input_text);
    int words_count = count_words(input_text);
    int sentences_count = count_sentences(input_text);
    int index = calculate_readability_index(letters_count, words_count, sentences_count);

    if (index > 16)
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

int count_letters(string text)
{
    long text_len = strlen(text);
    int letter_count = 0;

    for (int i = 0; i < text_len; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }

    return letter_count;
}

int count_words(string text)
{
    long text_len = strlen(text);
    int spaces = 0;

    if (text_len <= 0)
    {
        return spaces;
    }

    int next_indx;
    for (int i = 0; i < text_len; i++)
    {
        if (isblank(text[i]))
        {
            spaces++;

            // check if there are multiple spaces
            next_indx = i + 1;
            while (isblank(text[next_indx]))
            {
                next_indx++;
                i = next_indx;
            }
        }
    }

    return spaces + 1;
}

int count_sentences(string text)
{
    long text_len = strlen(text);

    int count = 0;
    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

int calculate_readability_index(double letters, double words, double sentences)
{
    // printf("%f letters\n", letters);
    // printf("%f words\n", words);
    // printf("%f sentences\n", sentences);

    // L is the average number of letters per 100 words in the text
    // S is the average number of sentences per 100 words in the text
    // index = 0.0588 * L - 0.296 * S - 15.8;

    double L = (letters / words) * 100;
    double S = 100 / (words / sentences);
    int index = (int) round((0.0588 * L) - (0.296 * S) - 15.8);

    return index;
}
