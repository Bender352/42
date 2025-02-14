#include <stdio.h>

void format_string(char *str)
{
    int i = 0, j = 0;
    int space = 1; // To track leading and multiple spaces
    
    // Skip leading spaces
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            if (!space) // Only add one space
                str[j++] = ' ';
            space = 1;
        }
        else
        {
            str[j++] = str[i];
            space = 0;
        }
        i++;
    }
    
    // Remove trailing space
    if (j > 0 && str[j - 1] == ' ')
        j--;
    
    str[j] = '\0'; // Null-terminate the formatted string
}

int main()
{
    char str[] = "    This     is a string  !    ";
    format_string(str);
    printf("%s\n", str);
    return 0;
}