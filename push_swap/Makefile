CC = cc
FLAGS = -Wall -Werror -Wextra
SRC_PATH = ./src/
OBJ_PATH = ./obj/
SRC_FILES = error_handling \
			check_input \
			check_for_doubles \
			the_turk_extension \
			shoves_things_arround \
			set_targets \
			init_stacks \
			is_sorted \
			print_move \
			fill_stack \
			the_turk \
            ft_split \
            new_node \
            push_swap \
			stack_handling \
			sa_move \
			sb_move \
			ra_move \
			rb_move \
			rr_move \
			rra_move \
			rrb_move \
			rrr_move \
			pa_move \
			pb_move \
			sort3 \
			sort2 \
			move_nodes \
			push_to_top \
			rotate_stacks \
			set_index \
			free_stuff

SRC_NAME = $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC_FILES)))
OBJ_NAME = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(SRC_FILES)))
OUTPUT = push_swap
NAME = library.a

all: $(OUTPUT)

$(OUTPUT): $(OBJ_NAME)
	$(CC) $(FLAGS) -g -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) -g -c $< -o $@

run: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OBJ_NAME)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(OUTPUT)

re: fclean all

rec: fclean all
	clear

.PHONY: all clean fclean re run clear
