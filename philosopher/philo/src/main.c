/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:23:02 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/18 08:13:23 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*action(void *data)
{
	t_cowboy	data;

	data = *((*t_cowboy)data);

	return NULL;
}

int	main(int arc, char **argv)
{
	t_cowboy	ugly;
	t_cowboy	bad;

	ugly.name = "ugly";
	bad.name = "bad";

	pthread_create(&ugly.thread, NULL, action, &ugly);
	pthread_create(&bad.thread, NULL, action, &bad);

	pthread_join(ugly.thread, NULL);
	pthread_join(bad.thread, NULL);
}