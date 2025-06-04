/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:46:27 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 19:12:05 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	g_exit_signal = 0;

int	main2(t_minishell *sh, char *input)
{
	start_execution(&sh->env_node, 0, sh);
	free_all(input, &sh->token, &sh->cmd);
	if (isatty(STDIN_FILENO) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av, char *envp[])
{
	char		*input;
	t_minishell	*sh;

	sh = malloc(sizeof(t_minishell));
	init_structs(&sh);
	start_init(&sh, envp, ac, av);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sigint_handler);
		input = get_user_input();
		if (!input)
			break ;
		add_history(input);
		if (handle_token(&sh, input) != 0)
		{
			free_all(input, &sh->token, &sh->cmd);
			continue ;
		}
		free_tokens(&sh->token);
		if (main2(sh, input))
			break ;
	}
	final_free(&sh->token, sh->env_node, sh);
}
