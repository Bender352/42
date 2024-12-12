#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

#define DICT_SIZE 1024

t_dict *parse_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Dict Error\n");
        return NULL;
    }

    t_dict *dictionary = malloc(sizeof(t_dict) * DICT_SIZE);
    if (!dictionary) {
        printf("Dict Error\n");
        fclose(file);
        return NULL;
    }

    char line[256];
    int index = 0;

    while (fgets(line, sizeof(line), file)) {
        char *number;
        char *value;
        char *token = strtok(line, ":");
        if (!token) continue;

        number = strdup(token);
        token = strtok(NULL, "\n");
        if (!token) continue;

        value = strdup(token);
        if (!value) continue;

        dictionary[index].number = number;
        dictionary[index].value = value;
        index++;
    }

    fclose(file);
    dictionary[index].number = NULL; // Mark the end of the dictionary
    return dictionary;
}

void free_dictionary(t_dict *dictionary) {
    if (dictionary) {
        for (int i = 0; dictionary[i].number != NULL; i++) {
            free(dictionary[i].number);
            free(dictionary[i].value);
        }
        free(dictionary);
    }
}

char *find_in_dict(const char *number, t_dict *dictionary) {
    for (int i = 0; dictionary[i].number != NULL; i++) {
        if (strcmp(dictionary[i].number, number) == 0) {
            return dictionary[i].value;
        }
    }
    return NULL;
}

void append_to_result(char **result, const char *addition) {
    size_t len = strlen(*result) + strlen(addition) + 2;
    *result = realloc(*result, len);
    if (strlen(*result) > 0) {
        strcat(*result, " ");
    }
    strcat(*result, addition);
}

char *number_to_words(const char *number, t_dict *dictionary, int is_german) {
    char *result = malloc(1);
    if (!result) return NULL;
    result[0] = '\0';

    if (strcmp(number, "0") == 0) {
        char *zero = find_in_dict("0", dictionary);
        if (zero) {
            result = realloc(result, strlen(zero) + 1);
            strcpy(result, zero);
        }
        return result;
    }

    const char *units[] = {
        "1000000000000000000000000000000000000", // undecillion
        "1000000000000000000000000000000000",   // decillion
        "1000000000000000000000000000000",      // nonillion
        "1000000000000000000000000000",         // octillion
        "1000000000000000000000000",            // septillion
        "1000000000000000000000",               // sextillion
        "1000000000000000000",                  // quintillion
        "1000000000000000",                     // quadrillion
        "1000000000000",                        // trillion
        "1000000000",                           // billion
        "1000000",                              // million
        "1000",                                 // thousand
        "100",                                  // hundred
        "90", "80", "70", "60", "50", "40", "30", "20", 
        "19", "18", "17", "16", "15", "14", "13", "12", "11", 
        "10", "9", "8", "7", "6", "5", "4", "3", "2", "1"
    };

    for (size_t i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        unsigned long long unit_value = strtoull(units[i], NULL, 10);
        unsigned long long num_value = strtoull(number, NULL, 10);

        if (num_value >= unit_value) {
            unsigned long long count = num_value / unit_value;
            char count_str[21];
            snprintf(count_str, 21, "%llu", count);

            char *sub_result = number_to_words(count_str, dictionary, is_german);
            append_to_result(&result, sub_result);
            free(sub_result);

            unsigned long long remainder = num_value % unit_value;
            char remainder_str[21];
            snprintf(remainder_str, 21, "%llu", remainder);

            if (remainder != 0) {
                char *remainder_result = number_to_words(remainder_str, dictionary, is_german);
                append_to_result(&result, remainder_result);
                free(remainder_result);
            } else {
                char *word = find_in_dict(units[i], dictionary);
                if (word) {
                    append_to_result(&result, word);
                }
            }
            break;
        }
    }

    return result;
}

