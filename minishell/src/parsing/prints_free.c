/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:04:07 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/29 18:06:02 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	print_token(t_token *token)
{
	if (token && token->str)
	{
		printf("token value :\"%s\"", token->str);
		printf("token type %i\n", token->type);
		printf("is redir : %i\n", token->is_redir_file);
		printf("type: %i\n", token->type);
		printf("----------------------------------\n");
	}
	else
		return ;
	if (token->next != NULL)
		print_token(token->next);
}

void	free_tokens(t_token **token)
{
	t_token	*temp;

	while (*token != NULL)
	{
		temp = (*token)->next;
		free((*token)->str);
		(*token)->str = NULL;
		free(*token);
		*token = temp;
	}
	*token = NULL;
}

void	print_redir(t_redir *redir, int type)
{
	if (redir == NULL)
		return ;
	if (type == 1)
		printf("redir in : %s\n", redir->file);
	else
		printf("redir out : %s\n", redir->file);
	print_redir(redir->next, type);
}

void	free_redir(t_redir *redir)
{
	t_redir	*temp;

	while (redir)
	{
		temp = redir->next;
		if (redir->heredock)
		{
			unlink(redir->heredock);
			free(redir->heredock);
		}
		free(redir->file);
		free(redir);
		redir = temp;
	}
}

void	free_cmd(t_command **cmd)
{
	t_command	*temp;
	int			i;

	while ((*cmd))
	{
		temp = (*cmd)->next;
		if ((*cmd)->exec)
			free((*cmd)->exec);
		if ((*cmd)->args)
		{
			i = 0;
			while ((*cmd)->args[i])
			{
				free((*cmd)->args[i]);
				i++;
			}
			free((*cmd)->args);
		}
		free_redir((*cmd)->infile);
		free_redir((*cmd)->outfile);
		free((*cmd));
		*cmd = temp;
	}
}
