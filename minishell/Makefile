# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 14:24:06 by knjaloun          #+#    #+#              #
#    Updated: 2025/05/29 19:05:03 by knjaloun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = minishell.a
SRC = ./src/main.c ./src/parsing/start_screen.c\
	./src/parsing/user_input.c ./src/parsing/tokenizer.c\
	./src/parsing/token_utils.c ./src/parsing/check_quote.c\
	./src/buildin/is_buildin.c ./src/parsing/token_str.c\
	./src/parsing/expand_utils.c ./src/parsing/token_str_utils.c\
	./src/env/env_utils.c ./src/env/env_parsing.c\
	./src/parsing/token_list.c ./src/parsing/prints_free.c\
	./src/parsing/token_utils2.c ./src/parsing/command_list.c\
	./src/parsing/commands.c ./src/parsing/command_utils.c\
	./src/parsing/helpfunk.c ./src/signals/signals_handler.c\
	./src/execution/exec.c ./src/execution/execution.c\
	./src/execution/exec_utils.c ./src/execution/exec_utils2.c\
	./src/execution/exec_nonbuildin.c ./src/execution/helpfunk2.c\
	./src/parsing/parsing_start.c ./src/execution/handle_heredock.c\
	./src/execution/handle_outfile.c ./src/execution/handle_infile.c\
	./src/execution/exec_builtin.c ./src/execution/exec_builtin_echo.c\
	./src/execution/exec_builtin_env.c ./src/execution/exec_builtin_export.c\
	./src/execution/exec_builtin_pwd.c ./src/execution/exec_builtin_unset.c\
	./src/execution/exec_builtin_cd.c ./src/parsing/get_token_len.c\
	./src/execution/exec_builtin_export_2.c ./src/execution/exec_builtin_exit.c\
	./src/execution/export_sort.c ./src/execution/exec_builtin_cd_helper_1.c\
	./src/execution/is_new_terminal.c ./src/execution/exec_builtin_exit_helper_1.c\
	./src/execution/exec_builtin_export_3.c ./src/execution/exec_helper_1.c\
	./src/execution/exec_helper_2.c ./src/execution/exec_helper_3.c\
	./src/execution/heredock_line_expand.c ./src/parsing/get_token_len_utils.c\
	./src/parsing/get_token_len_utils2.c ./src/parsing/token_str_utils2.c\
	./src/parsing/token_utils3.c ./src/parsing/helpfunk2.c\
	./src/parsing/helpfunk3.c


EXEC = minishell
RM = rm -rf
CFlags = -Wall -Werror -Wextra
OBJS = $(SRC:.c=.o)
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)/libftprintf.a

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m


$(EXEC) : $(Name)
	@cc  -g $(Name) -o $(EXEC) -lreadline
	@echo -e "$(GREEN)Building Project sucessfull$(NC)"
$(Name) : $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(Name)
	@ar rc $(Name) $(OBJS)
 $(LIBFT) : 
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	@cc $(CFlags) -g -c -o $@ $<

all : $(EXEC)

clean : 
	@$(MAKE)  -C $(LIBFT_PATH) fclean
	@$(RM) $(OBJS)
	@$(RM) $(EXEC)
	@echo -e "$(RED)Removed Objects$(NC)"

fclean : clean
	@$(MAKE)  -C $(LIBFT_PATH) clean
	@$(RM) $(Name)
	@echo -e "$(RED)Removed lib and Exec$(NC)"


re : fclean all

.PHONY: all re clean fclean

