/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:25:33 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/03 19:17:08 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

    #include <unistd.h>
    #include <signal.h>
    #include "libft/libft.h"
    #include "ft_printf/ft_printf.h"

    void	handle_signal(int sig, siginfo_t *i, void *context);    

#endif