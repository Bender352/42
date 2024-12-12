#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

#define DICT_SIZE 1024

t_dict *parse_dictionary(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Dict Error\n");
        return NULL;
    }

    t_dict *dictionary = malloc(sizeof(t_dict) * DICT_SIZE);
    if (!dictionary)
    {
        printf("Dict Error\n");
        return NULL;
    }

    char line[256];
    int index = 0;

    while (fgets(line, sizeof(line), file))
    {
        unsigned long long number;
        char *value;
        char *token = strtok(line, ":");
        if (!token)
            continue;

        number = strtoull(token, NULL, 10);
        token = strtok(NULL, "\n");
        if (!token)
            continue;

        value = strdup(token);
        if (!value)
            continue;

        dictionary[index].number = number;
        dictionary[index].value = value;
        index++;
    }

    fclose(file);
    dictionary[index].value = NULL; // Mark the end of the dictionary
    return dictionary;
}

void free_dictionary(t_dict *dictionary)
{
    if (dictionary)
    {
        for (int i = 0; dictionary[i].value != NULL; i++)
        {
            free(dictionary[i].value);
        }
        free(dictionary);
    }
}

char *find_in_dict(unsigned long long number, t_dict *dictionary)
{
    for (int i = 0; dictionary[i].value != NULL; i++)
    {
        if (dictionary[i].number == number)
        {
            return dictionary[i].value;
        }
    }
    return NULL;
}

void append_to_result(char **result, const char *addition)
{
    size_t len = strlen(*result) + strlen(addition) + 2;
    *result = realloc(*result, len);
    strcat(*result, " ");
    strcat(*result, addition);
}

char *number_to_words(unsigned long long number, t_dict *dictionary, int is_german)
{
    char *result = malloc(1);
    if (!result)
        return NULL;
    result[0] = '\0';

    if (number == 0)
    {
        char *zero = find_in_dict(0, dictionary);
        if (zero)
        {
            result = realloc(result, strlen(zero) + 1);
            strcpy(result, zero);
        }
        return result;
    }

    unsigned long long units[] = {
        1000000000000000000, 1000000000000000, 1000000000000,
        1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50,
        40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 5, 4, 3, 2, 1};

    for (size_t i = 0; i < sizeof(units) / sizeof(units[0]); i++)
    {
        if (number >= units[i])
        {
            unsigned long long count = number / units[i];
            number %= units[i];

            if (units[i] >= 100)
            {
                char *sub_result = number_to_words(count, dictionary, is_german);
                append_to_result(&result, sub_result);
                free(sub_result);
            }

            if (is_german == 1 && units[i] >= 20 && units[i] < 100)
            {
                unsigned long long units_part = number % 10;
                if (units_part != 0)
                {
                    char *unit_word = find_in_dict(units_part, dictionary);
                    char *ten_word = find_in_dict(units[i], dictionary);
                    if (unit_word && ten_word)
                    {
                        size_t len = strlen(unit_word) + strlen(" und") + strlen(ten_word) + 1;
                        char *combined_word = malloc(len);
                        snprintf(combined_word, len, "%s und%s", unit_word, ten_word);
                        append_to_result(&result, combined_word);
                        free(combined_word);
                        number -= units_part;
                    }
                }
                else
                {
                    char *word = find_in_dict(units[i], dictionary);
                    if (word)
                    {
                        append_to_result(&result, word);
                    }
                }
            }
            else if (is_german == 2 && units[i] >= 20 && units[i] < 100)
            {
                unsigned long long units_part = number % 10;
                if (units_part != 0)
                {
                    char *unit_word = find_in_dict(units_part, dictionary);
                    char *ten_word = find_in_dict(units[i], dictionary);
                    if (unit_word && ten_word)
                    {
                        size_t len = strlen(unit_word) + strlen(" an") + strlen(ten_word) + 1;
                        char *combined_word = malloc(len);
                        snprintf(combined_word, len, "%s an%s", unit_word, ten_word);
                        append_to_result(&result, combined_word);
                        free(combined_word);
                        number -= units_part;
                    }
                }
                else
                {
                    char *word = find_in_dict(units[i], dictionary);
                    if (word)
                    {
                        append_to_result(&result, word);
                    }
                }
            }
            else
            {
                char *word = find_in_dict(units[i], dictionary);
                if (word)
                {
                    append_to_result(&result, word);
                }
            }
        }
    }

    return result;
}

int len_str(char *c)
{
    int i;

    i = 0;
    while (c[i])
    {
        i++;
    }
    return (i);
}
