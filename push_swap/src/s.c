#include "pushswap.h"

void    (t_struct **stack)
{
    t_struck    *buf;

    buf = NULL;
    if (*(stack) == NULL || *(stack)->next == NULL)
        return (NULL);
    buf = *(stack);
    *(stack) = *(stackt)->next;
    *(stack)->prev = NULL;
    
}