/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:22:27 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/04 22:11:36 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

    #include "libft/libft.h"
    #include "ft_printf/ft_printf.h"
    #include <signal.h>
        
    void    send_bit(int pid, int bit);

#endif

#ifndef BIT_LEN
# define BIT_LEN 8
#endif