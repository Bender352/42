/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:01:05 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/12 21:51:17 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "unistd.h"
#include "stdio.h"

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
int     ft_strlen(char *str);
t_stack *new_stack();
char	**ft_split(char const *s, char c);
t_stack **fill_stack(char    **str);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);







# endif