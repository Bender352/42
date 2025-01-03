/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:25:33 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/03 23:22:12 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

    #include <unistd.h>
    #include <signal.h>
    #include "libft/libft.h"
    #include "ft_printf/ft_printf.h"

    void	handle_signal(int sig, siginfo_t *i, void *context);  
    void print_char_binary(unsigned char c);  

#endif