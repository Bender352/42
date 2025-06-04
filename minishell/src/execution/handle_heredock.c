/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:17:52 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 19:27:01 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	open_heredoc_file(char **heredoc_file)
{
	static unsigned int	num = 0;
	char				*pid_str;
	char				*num_str;
	char				*tmp;
	int					fd;

	pid_str = ft_itoa(getpid());
	num_str = ft_itoa(num++);
	tmp = ft_strjoin("/tmp/heredoc_", pid_str);
	*heredoc_file = ft_strjoin(tmp, num_str);
	free(pid_str);
	free(num_str);
	free(tmp);
	fd = open(*heredoc_file, O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if (fd < 0)
		perror("open heredoc tmp");
	return (fd);
}

static void	read_heredoc_content(int fd, char *del, t_env *env)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (!input || ft_cmp(input, del) == 1)
		{
			free(input);
			break ;
		}
		expand_dock(&input, env);
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
}

static int	get_fd(int edit, int fdi)
{
	static int	fd = 0;

	if (edit == 1)
		fd = fdi;
	return (fd);
}

void	heredock_siquit(int sig)
{
	int	fd;

	(void)sig;
	fd = get_fd(0, 0);
	if (fd > 0)
		close(fd);
	signal(SIGINT, SIG_DFL);
	kill(0, SIGINT);
	write(2, "\n", 1);
	g_exit_signal = 130;
	close(STDIN_FILENO);
}

int	handle_heredock(t_redir *infile, char *del, int dock, t_env *env)
{
	char	*heredoc_file;
	int		fd;
	pid_t	pid;

	if (dock == 0 || infile->heredock)
		return (0);
	fd = open_heredoc_file(&heredoc_file);
	get_fd(1, fd);
	if (fd == -1)
		error_exit("heredoc");
	infile->heredock = heredoc_file;
	pid = fork();
	if (pid == 0)
	{
		heredock_signal();
		read_heredoc_content(fd, del, env);
		close(fd);
		exit(0);
	}
	if (finish_dock(pid, fd) == 1)
		return (1);
	return (0);
}
