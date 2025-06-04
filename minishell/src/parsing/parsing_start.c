/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:55:28 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 18:01:48 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	token_handler2(t_minishell **sh, char *input)
{
	tokenizer(&(*sh)->token, input, &(*sh)->error, (*sh)->env_node);
	set_token_type((*sh)->token, &(*sh)->error, (*sh)->env_node);
	set_token_redirection((*sh)->token, &(*sh)->error);
	validate_input((*sh)->token, (*sh)->error);
	init_command((*sh)->token, &(*sh)->cmd, (*sh)->error);
}

void	free_all(char *input, t_token **token, t_command **cmd)
{
	free(input);
	free_tokens(token);
	free_cmd(cmd);
}

void	start_init(t_minishell **sh, char *envp[], int ac, char **av)
{
	(*sh)->env_node = NULL;
	(*sh)->token = NULL;
	(void)ac;
	(void)av;
	env_init(&(*sh)->env_node, envp);
	increment_shlvl(&(*sh)->env_node);
}

int	handle_token(t_minishell **sh, char *input)
{
	int	error_code;

	(*sh)->error = malloc(sizeof(t_error));
	(*sh)->error->error = 0;
	if (!input || *input == '\0' || ft_strisspace(input))
	{
		free((*sh)->error);
		if (input == NULL)
			free_envs((*sh)->env_node);
		return (1);
	}
	if (ft_strlen(input) > 50000)
	{
		printf("input is too long\n");
		free((*sh)->error);
		return (1);
	}
	token_handler2(sh, input);
	error_code = (*sh)->error->error;
	free((*sh)->error);
	return (error_code);
}
