/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:18:32 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/25 15:43:47 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *s, ...);
int			ft_print_char(char c, int fd);
int			ft_check_conversion(char s, va_list arg);
int			ft_print_str(char *s, int fd);
char		*ft_convert_toascii(int num);
int			ft_print_base10(int num);
char		*ft_uitoa(unsigned int num);
int			ft_print_unumber(unsigned int num);
int			ft_print_uint(unsigned int num);
int			ft_printf_hex(unsigned int num, short isupper);
int			ft_printf_ptrhex(unsigned long long ptr);
#endif
