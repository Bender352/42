/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:48:27 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/04 11:56:46 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>


typedef struct s_stack
{
    long int        i;
    int             index;
    int             cost_push;
    int             cost_rotate;
    bool            cheapst;
    bool            above_median;
    struct s_stack  *target;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

typedef struct s_mothership
{
    t_stack         **stack_a;
    t_stack         **stack_b;
    char            **temp;
    char            *error_msg;
}   t_mothership;

void    print_stack(t_stack **stack);

t_stack *new_node(long int  i);
int     find_smallest (t_stack **list);
int     find_highest (t_stack **list);
char	**ft_split(char const *s, char c);
size_t  ft_strlen(char *str);
int     fill_stack(t_mothership *mother);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void    free_stack(t_stack  **stack_a, t_stack **stack_b);
void    free_array(char **pntstr);
int     element_count (char **str);
long    ft_atol(const char *str);

void    print_move(char *str);

void    show_error(t_mothership *m);

void    push_all_to_a(t_stack **stack_a, t_stack **stack_b);
void    highest_on_top(t_stack  **stack);
void    bubble_sort(t_stack **stack_a, t_stack **stack_b);

int     count_nodes(t_stack **stack);

t_stack *last_node(t_stack  *list);

//void    s(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
//void    p(t_stack **stack_from, t_stack **stack_to);
void    pa(t_mothership *m);
void    pb(t_mothership *m);
//void    rotate_stack(t_stack **stack);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
//void    rev_rotate_stack(t_stack **stack);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
void    do_the_turk(t_mothership *m);
void    sort_method(t_mothership *m, int total_nodes);

void    sort3(t_stack   **head);
void    sort2(t_stack **stack_a);
void    if_2(t_stack **head);
void    if_3(t_stack **head);

void    set_index (t_stack **stack);
void    ini_stack_a(t_mothership *m);
void    ini_stack_b(t_mothership *m);
bool    is_stack_sorted(t_stack **stack);
void    sort_stack(t_mothership *m);
void    set_target_a(t_mothership *m);
void    set_target_b(t_mothership *m);
void    set_cost(t_mothership *m);
void    set_cheapest_node(t_stack **stack);
void    shove_b_to_a(t_mothership *m);
void    shove_a_to_b(t_mothership *m);
t_stack *find_highest_i_node(t_stack **stack);
t_stack *find_smallest_i_node(t_stack **stack);
t_stack *get_cheapest_node(t_stack **a);
void    rr_all(t_mothership *m, t_stack *cheapy);
void    rrr_all(t_mothership *m, t_stack *cheapy);
void    prep_a_to_push(t_mothership *m, t_stack *top);
void    prep_b_to_push(t_mothership *m, t_stack *top);
void    prep_for_pushing(t_stack **stack, t_stack *top);
void    min_on_top(t_mothership *m);

int     main(int arg, char **argv);

#endif