.PHONY: all clean fclean re
.SILENT:

NAME = 21sh

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3 -I ./includes -I $(LBFT_PATH)

SRC_PATH = ./sources/
RACINE =	main.c\
			$(addprefix parsing/,$(PARSING_NAME))\
			$(addprefix struct/,$(STRUCT_NAME))\
			$(addprefix display/,$(DISPLAY_NAME))
INC_PATH = ./includes/
LBFT_PATH = ./libft/
LIBFT =		./libft/libft.a

SRC = $(addprefix $(SRC_PATH),$(RACINE))
OBJ = $(SRC:.c=.o)
INC = $(addprefix -I,$(INC_PATH))

INC_NAME = 21sh.h
PARSING_NAME =		extract_cmd.c\
					extract_operator.c \
					extract_utils.c\
					tokenization.c

STRUCT_NAME =		t_token.c

DISPLAY_NAME =		error.c

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LBFT_PATH)
	clear
	$(CC) -o $(NAME) $(OBJ) -L $(LBFT_PATH) -lft $(LIBFT)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
	printf "\033[32m\033[1m\033[4mCompiling\033[0m\033[32m : %-35s\033[0m [$(NAME)]\n" $@

clean:
	make -C $(LBFT_PATH) clean
	rm -rf $(OBJ)

fclean:
	make -C $(LBFT_PATH) fclean
	rm -f $(NAME)
	rm -rf $(OBJ)

re: fclean all
