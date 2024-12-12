/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:01:05 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/12 19:39:13 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "unistd.h"
#include "stdio.h"

# ifndef S_LIST
#define S_LIST

typedef struct s_list
{
    
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;


# endif

int main(int arg, char **argv);
int word_count(char *str, char seperator);
int ft_strlen(char *str);







# endif