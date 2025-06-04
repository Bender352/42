/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_buildin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:04:12 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 19:00:44 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

/*@brief this funktion check if the input match with a buildin command
*@param str the value of a token to compare
@return returns 1 if the argument matches a buildin command esle it returns 0
*/
int	is_buildin(char *str)
{
	if (ft_cmp(str, "echo") || ft_cmp(str, "cd"))
	{
		return (1);
	}
	if (ft_cmp(str, "pwd") || ft_cmp(str, "export"))
	{
		return (1);
	}
	if (ft_cmp(str, "unset") || ft_cmp(str, "env"))
		return (1);
	if (ft_cmp(str, "exit"))
		return (1);
	return (0);
}
