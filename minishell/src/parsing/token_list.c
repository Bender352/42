/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:49:58 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/28 21:57:45 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	start_token_list(t_token **token, char *str, t_error **error, int type)
{
	if ((*token) == NULL)
		(*token) = fst_token(str, error, type);
	else
		add_token_end(str, *token, error, type);
}

t_token	*fst_token(char *str, t_error **error, int type)
{
	t_token	*head;

	head = malloc(sizeof(t_token));
	if (head == NULL)
	{
		(*error)->error = MEM_ERROR;
		return (NULL);
	}
	head->is_redir_file = 0;
	head->q_type = type;
	head->type = 0;
	head->next = NULL;
	head->prv = NULL;
	head->str = str;
	return (head);
}

void	add_token_end(char *str, t_token *token, t_error **error, int type)
{
	while (token->next != NULL)
		token = token->next;
	token->next = malloc(sizeof(t_token));
	if (token->next == NULL)
	{
		(*error)->error = MEM_ERROR;
		return ;
	}
	token->next->is_redir_file = 0;
	token->next->q_type = type;
	token->next->type = 0;
	token->next->next = NULL;
	token->next->prv = token;
	token->next->str = str;
}
