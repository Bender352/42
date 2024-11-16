/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:50:35 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/09 18:50:37 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_put_char(char c, size_t *count_char);
void	ft_print_str(char *str, size_t *count);
void	ft_handle_variables(const char c, va_list args, size_t *count_char);
void	ft_handle_num(char *base, long long int i, size_t *count);
void	ft_ptr_add(void *ptr, size_t *count);
char	*ft_base_hex(char c);
char	*ft_base_num(void);
int		ft_str_len(char *str);
