#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct s_dict {
    char *number; // Change to string to handle large numbers
    char *value;
} t_dict;

t_dict *parse_dictionary(const char *filename);
char *number_to_words(const char *number, t_dict *dictionary, int is_german);
void free_dictionary(t_dict *dictionary);

#endif

