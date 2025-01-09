/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:30:26 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/04 02:25:02 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

    #include "libft/libft.h"
    #include "ft_printf/ft_printf.h"
    #include <signal.h>
        
    void    send_bit(int server_pid, int i);
    void    send_pid(int server_pid);
    void	handle_signal(int sig, siginfo_t *i, void *context);
    void    list_ack();
    
#endif
