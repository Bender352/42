/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:43:16 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 19:34:09 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define PURPLE "\e[0;35m"
# define COLOR_END "\33[0m"

# define PATH_MAX 4096

extern int				g_exit_signal;

typedef enum e_type
{
	COMMAND = 1,
	PIPE = 2,
	REDIR_OUT = 3,
	REDIR_IN = 4,
	REDIR_OUT_A = 5,
	HERE_DOCK = 6,
	D_QUOTE = 7,
	S_QUOTE = 8,
	ARGUMENT = 9,
	NO_QUOTE = 10
}						t_type;

typedef enum e_error_list
{
	UNCLOSED_QUOTE = 1,
	UNEXPECTED_WORD = 2,
	UNOWN_COMMAND = 3,
	MEM_ERROR = 4,
	EMPTY
}						t_error_list;

typedef struct s_token
{
	int					type;
	char				*str;
	t_type				q_type;
	int					is_redir_file;
	struct s_token		*next;
	struct s_token		*prv;
}						t_token;

typedef struct s_quote_state
{
	int					double_quote;
	int					single_quote;
	int					in_quote;
	char				del;
}						t_quote_state;

typedef struct s_env
{
	char				*name;
	char				*value;
	int					env_hide;
	struct s_env		*next;
}						t_env;

typedef struct s_minishell
{
	struct s_token		*token;
	struct s_env		*env_node;
	struct s_command	*cmd;
	struct s_error		*error;
}						t_minishell;

typedef struct s_loop
{
	int					i;
	int					j;
}						t_loop;

typedef struct s_command
{
	char				**args;
	char				*exec;
	struct s_redir		*outfile;
	struct s_redir		*infile;
	int					pipe;
	struct s_command	*next;
}						t_command;

typedef struct s_redir
{
	char				*file;
	int					type;
	struct s_redir		*next;
	char				*heredock;
}						t_redir;

typedef struct s_error
{
	int					error;
	int					saved_stdin;
	int					saved_stdout;
}						t_error;

typedef struct s_echo_data
{
	pid_t				*pid;
	int					*prevfd;
	int					*fd;
	t_env				**env;
	t_minishell			*sh;
	t_command			*head;
	int					*index;
	int					just_redir;
	int					infile_error;
}						t_echo_data;

typedef struct s_fd
{
	int					fd[2];
	int					prev_fd[2];
}						t_fd;

typedef struct s_managestr
{
	char				*joined_str;
	char				del;
	char				*value_str;
	char				*temp;
	int					found_b_slash_quote;
	char				prev_del;
}						t_mstr;

typedef struct s_cd_builtin
{
	char				*cwd;
	char				*old_pwd_path;
	char				*target;
	char				**args;
	t_env				**env;
	t_command			*cmd;
	t_minishell			*sh;
	t_echo_data			*data;
	t_fd				*fd;

}						t_cd_builtin;

typedef struct s_henv
{
	int		i;
	int		name_len;
	int		value_len;
	char	*name;
	char	*value;
}						t_henv;

typedef struct s_tokenlen
{
	int					count;
	int					quotes;
	int					found_end;
	int					remaining_quotes;
}						t_tlen;

typedef struct s_sq
{
	int		i;
	int		quotes;
	char	del;
	int		update_del;
}						t_sq;

typedef struct s_rquote
{
	int		i;
	char	*temp;
	char	*new_str;
	char	*append_not_quote;
}						t_rquote;

char					*get_user_input(void);
void					tokenizer(t_token **token, char *input, t_error **error,
							t_env *env);
t_token					*fst_token(char *str, t_error **error, int type);
void					add_token_end(char *str, t_token *token,
							t_error **error, int type);
void					free_tokens(t_token **token);
void					print_token(t_token *token);
int						ft_cmp(char *s1, char *s2);
int						is_buildin(char *str);
void					set_token_type(t_token *token, t_error **error,
							t_env *env);
int						get_special_operation(t_token *token);
void					add_env_end(t_env *env, char *name, char *value,
							int hide);
t_env					*fst_env_node(t_env **env, char *name, char *value,
							int hide);
void					print_env(t_env *env);
void					env_init(t_env **env, char **env_list);
void					free_envs(t_env *env);
char					*get_env_value(char *name, t_env *env);
int						is_command(t_token *token, int can_be_command,
							t_env *env);
void					check_empty_token(t_token **token, t_error **error);
void					set_token_redirection(t_token *token, t_error **error);
void					validate_input(t_token *token, t_error *error);
t_command				*fst_command_node(t_command *cmd);
void					add_cmd_end(t_command *cmd);
int						get_arguemnts_count(t_token *token);
void					print_command(t_command *cmd);
void					init_command(t_token *token, t_command **cmd,
							t_error *error);
t_token					*set_commands(t_command *cmd, t_token *token);
void					free_cmd(t_command **cmd);
void					init_cmd_args(int len, t_command *cmd);
t_redir					*fst_redir_list(char *value, int type);
void					list_redir_end(t_redir *redir, char *value, int type);
void					set_redir(t_token *token, t_command *cmd);
void					cmd_check(t_command *cmd, t_token *token);
int						set_command_helpfunk(t_token *token, t_command *cmd,
							int *i, t_token *head);
void					set_commmand_argv_ppath(t_token *token, t_command *cmd);
void					set_cmd_args(t_token *token, t_command *cmd, int pos);
void					set_redirection_helpfunk(int *is_next_redir,
							t_token *token, int type);
void					free_empty_token(t_token *curr);
void					set_token_type_helpfunk(int *count_down,
							int *can_be_command);
int						ft_strisspace(const char *s);
void					init_structs(t_minishell **sh);
void					sigint_handler(int sig);
void					final_free(t_token **token, t_env *env_node,
							t_minishell *sh);
void					token_handler2(t_minishell **sh, char *input);
void					free_all(char *input, t_token **token, t_command **cmd);
void					start_init(t_minishell **sh, char *envp[], int ac,
							char **av);
int						handle_token(t_minishell **sh, char *input);
int						skip_whitespace(char *input);
int						get_next_token_len(char *input, int i);
char					*get_token_str(int len, char *input, int start);
void					start_token_list(t_token **token, char *str,
							t_error **error, int type);
int						skip_quotes(char *input);
void					token_manage_str(t_token *token, t_env *env, int start,
							int count);
void					replace_with_quote(char **str, char delimiter);
void					expand_str(char **str, char del, t_env *env,
							t_token *token);
char					set_delimiter(char c);
int						quote_closed(t_error *error, char *input,
							t_quote_state state, int i);
void					remove_last_emptytoken(t_token *token, t_error *error);
int						to_search_quotes(char *input);
int						is_special_operation(char c);
int						special_case_check(char *input, int count,
							int saved_quotes);
void					init_1(t_tlen *tlen, char *input, int *i);
void					increment(int *i, t_tlen *tlen);
void					init_2(int *i, t_tlen *tlen, char *input);
int						schould_go_in(char *str, int i, char del, int *count);
void					manage_str_2(t_mstr *mstr, int *i, int *start,
							t_token *token);
int						is_non_buildin_command(t_token *token, t_env *env);
void					free_envpath(char **str);
void					replace_quote_help(t_rquote *rquote, char **str);
int						prev_isdock(t_token *token);
int						is_redir_operator(t_token *token);
int						skip_whitespace_and_set_delimiter(char *input,
							char *del);
void					initialize_quote_state(t_quote_state *state, char del);
void					update_quote_counts(t_quote_state *state);
/*---------------------------exec-----------------------------*/

void					start_execution(t_env **env, int i, t_minishell *sh);
void					init_prevfd(int *fd, int *prev_fd);
void					free_heredock(t_redir *infile);
int						open_infile(t_redir *infile);
int						count_env(t_env *env);
char					**build_envp(t_env *env);
void					free_envp(char **envp);
int						handle_infile(t_command *cmd, int dock);
int						handle_outfile(t_command *cmd);
void					close_fds(int *fd, int *prev_fd, t_command *cmd);
void					check_closefd(t_command *cmd, int *fd, int *prev_fd);
void					error_exit(char *file);
void					read_env_from_name_help(char **temp, char **str,
							char **env_value, char **value);
int						handle_heredock(t_redir *infile, char *del, int dock,
							t_env *env);
int						exec_builtin(t_echo_data *data, t_fd fd);
void					builtin_unset(t_command *cmd, t_fd fd, t_env **env,
							t_echo_data *data);
int						builtin_echo(t_echo_data *data, t_fd fd);
int						env_builtin(t_env *env, t_fd fd, t_echo_data *data);
int						builtin_export(t_env **env, t_command *cmd,
							t_echo_data *data, t_fd fd);
int						builtin_pwd(t_fd fd, t_echo_data *data);
int						builtin_cd(t_echo_data *data, t_fd fd);
int						free_child(char **envp, t_command *cmd);
int						prepare_all_heredocs(t_command *cmd, t_env *env);
void					cleanup_heredocs(t_command *cmd);
void					close_all(int *fd, int *prev_fd, t_command *cmd);
void					wait_and_clean(int i, t_command *head, pid_t *pids);
void					wait_for_children(pid_t *pids, int i);
void					env_overwrite(t_env *env, char *name, char *data);
int						builtin_exit(t_minishell *sh, t_echo_data *data,
							t_fd fd);
void					store_pid(pid_t *pids, int *i, pid_t pid);
void					handle_pipefd(t_command *cmd, int *prevfd, int *fd);
void					free_split(char **str);
int						env_exits(t_env *env, char *name);
void					selection_sort(char **str);
void					init_cd_struct(t_cd_builtin *cd, t_command *cmd);
int						try_open_outfile(t_redir *outfile);
int						try_open_infile(t_redir *infile);
void					increment_shlvl(t_env **env);
int						update_oldpwd(t_env **env, char *oldpwd);
void					echo_print(char **args, int n_flag, int i);
int						update_pwd(t_env **env);
int						do_error(t_command *cmd, char *msg, int i,
							t_cd_builtin *cd);
int						do_chdir(char *target, t_command *cmd);
int						builtin_cd2(t_env **env, t_command *cmd);
void					handle_cd_redir(t_echo_data *data, t_fd fd,
							int invalid_infile);
int						is_numeric_exit(const char *str);
void					free_env(t_env **env);
int						helper_space_function(t_minishell *sh, int status);
int						builtin_exit2(t_minishell *sh, int infork);
void					handle_exit_redir(t_echo_data *data, t_fd fd,
							int invalid_infile);
int						export_error(t_command *cmd, t_env *env,
							t_echo_data *data, t_fd fd);
int						invalid_export_value(t_command *cmd, int *i,
							t_env **env);
void					free_export(char **name, char **str);
int						has_equal(char *str);
void					handle_execve(t_command *cmd, char **envp);
void					exec_child(t_command *cmd, int *prevfd, int *fd,
							t_env *env);
void					check_last_command(t_command *cmd);
void					after_child(t_fd *fd, int *i, pid_t pid,
							t_echo_data *data);
int						init_start_exec(t_command **cmd, t_command **head,
							t_fd *fd, t_env *env);
int						ft_hasnovalue(const char *s);
void					expand_init(int *i, char **new_str, char **append);
int						get_env_name(char *input, char **str, t_env *env);
void					expand_dock(char **str, t_env *env);
int						finish_dock(pid_t pid, int fd);
void					heredock_siquit(int sig);
void					heredock_signal(void);
#endif
