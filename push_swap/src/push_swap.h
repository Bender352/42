/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sven <sven@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:01:05 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/17 20:28:33 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef S_STACK
#define S_STACK

typedef struct s_stack
{
    int             i;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;


# endif


int     main(int arg, char **argv);
t_stack *new_node(int  i);
char	**ft_split(char const *s, char c);
size_t  ft_strlen(char *str);
void    fill_stack(t_stack **header, char **str);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void    free_stack(t_stack  **stack_a, t_stack **stack_b, t_stack *stack);
int     element_count (char **str);
int	    ft_atoi(const char *str);
void    s(t_stack **stack);
void    p(t_stack **stack_from, t_stack **stack_to);
void    r(t_stack **stack);
void    rr(t_stack **stack);
t_stack *last_node(t_stack  *list);







# endif