/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:59:54 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 17:51:38 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	init_command(t_token *token, t_command **cmd, t_error *error)
{
	t_token		*temp_token;
	t_command	*temp_cmd;

	temp_token = token;
	if (error->error != 0 || !token)
		return ;
	(*cmd) = fst_command_node(*cmd);
	temp_token = set_commands(*cmd, temp_token);
	temp_cmd = (*cmd);
	while (temp_token != NULL)
	{
		add_cmd_end((*cmd));
		temp_cmd = temp_cmd->next;
		temp_token = set_commands(temp_cmd, temp_token);
	}
}

char	*extract_name_from_path(t_token *token)
{
	char	*name;
	int		i;
	int		count;

	i = ft_strlen(token->str) - 1;
	count = 0;
	while (i != 0 && token->str[i] != '/')
	{
		count++;
		i--;
	}
	name = malloc(sizeof(char) * (count + 1));
	ft_strlcpy(name, token->str + i + 1, count + 1);
	return (name);
}

void	set_cmd_args(t_token *token, t_command *cmd, int pos)
{
	int	len;

	len = ft_strlen(token->str);
	cmd->args[pos] = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(cmd->args[pos], token->str, len + 1);
}

void	set_commmand_argv_ppath(t_token *token, t_command *cmd)
{
	int		len;
	char	*name;

	len = 0;
	free(cmd->args[0]);
	if (ft_strchr(token->str, '/') == NULL)
	{
		len = ft_strlen(token->str);
		cmd->exec = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(cmd->exec, token->str, len + 1);
		cmd->args[0] = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(cmd->args[0], token->str, len + 1);
	}
	else
	{
		name = extract_name_from_path(token);
		len = ft_strlen(token->str);
		cmd->exec = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(cmd->exec, token->str, len + 1);
		cmd->args[0] = name;
	}
}

t_token	*set_commands(t_command *cmd, t_token *token)
{
	int		len;
	int		i;
	t_token	*head;

	head = token;
	len = get_arguemnts_count(token);
	i = 1;
	cmd->args = malloc(sizeof(char *) * ((len) + 2));
	init_cmd_args((len), cmd);
	cmd->args[0] = ft_strdup("");
	cmd->args[(len) + 1] = NULL;
	while (token)
	{
		if (set_command_helpfunk(token, cmd, &i, head) == 1)
			return (token->next);
		token = token->next;
	}
	return (NULL);
}
