/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:48:27 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/04 17:46:41 by sbruck           ###   ########.fr       */
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
    int             index;
    int             cost_push;
    int             cost_rotate;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;


# endif

void    print_stack(t_stack **stack);

t_stack *new_node(int  i);
char	**ft_split(char const *s, char c);
size_t  ft_strlen(char *str);
int     fill_stack(t_stack **header, char **str);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void    free_stack(t_stack  **stack_a, t_stack **stack_b);
void    free_array(char **pntstr);
int     element_count (char **str);
int	    ft_atoi(const char *str);

t_stack *last_node(t_stack  *list);

void    s(t_stack **stack);
void    p(t_stack **stack_from, t_stack **stack_to);
void    r(t_stack **stack);
void    rr(t_stack **stack);

void    print_move(char *str);

void    sort_method(t_stack **stack_a, t_stack **stack_b, int total_nodes);

void    sort3(t_stack   **head);
void    if_2(t_stack **head);
void    if_3(t_stack **head);

int     main(int arg, char **argv);

# endif