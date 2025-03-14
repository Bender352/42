/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:22:45 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/04 22:11:39 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

    # include <unistd.h>
    # include <signal.h>
    # include <stdlib.h>
    # include "libft/libft.h"
    # include "ft_printf/ft_printf.h"

    void	ft_write_c (unsigned char *c, int *bits, pid_t pid);

#endif

#ifndef BIT_LEN
# define BIT_LEN 8
#endif