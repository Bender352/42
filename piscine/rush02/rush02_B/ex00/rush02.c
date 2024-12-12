#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

int main(int argc, char *argv[])
{

    int is_german = 0;

    if (argc < 2 || argc > 4)
    {
        printf("Error\n");
        return 1;
    }

    t_dict *dictionary;
    if (argc == 2)
    {
        dictionary = parse_dictionary("numbers_en.dict");
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "en") == 0)
            dictionary = parse_dictionary("numbers_en.dict");
        else if (strcmp(argv[1], "de") == 0)
        {
            dictionary = parse_dictionary("numbers_de.dict");
            is_german = 1;
        }
        else if (strcmp(argv[1], "lu") == 0)
        {
            dictionary = parse_dictionary("numbers_lu.dict");
            is_german = 2;
        }
        else if (strcmp(argv[1], "fr") == 0)
            dictionary = parse_dictionary("numbers_fr.dict");
        else
            dictionary = parse_dictionary(argv[1]);
    }
    else
    {
        dictionary = parse_dictionary(argv[1]);
    }

    if (!dictionary)
    {
        printf("Dict Error\n");
        return 1;
    }

    char *endptr;
    unsigned long long number = strtoull(argv[argc - 1], &endptr, 36);
    if (*endptr != '\0')
    {
        printf("Error\n");
        return 1;
    }

    char *result = number_to_words(number, dictionary, is_german);
    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    else
    {
        printf("Dict Error\n");
    }

    free_dictionary(dictionary);
    return 0;
}
