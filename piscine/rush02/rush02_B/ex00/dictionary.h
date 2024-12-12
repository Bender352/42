#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct s_dict {
    unsigned long long number;
    char *value;
} t_dict;

t_dict *parse_dictionary(const char *filename);
char *number_to_words(unsigned long long number, t_dict *dictionary, int is_german);
void free_dictionary(t_dict *dictionary);
int	len_str(char *c);

#endif
