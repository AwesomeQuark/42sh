# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoelstudent.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/06/18 19:54:19 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################################################
##################################### VARS ######################################
#################################################################################

NAME =			21sh
AUTEUR =		"mbonati/nconoel"

###### SOURCES #######

SRC_NAME =		main.c\
				$(LINE_EDITION)\
				$(LEXER_PARSER)

#sub-directories
	LINE_EDITION_SRC =		handlers.c\
							tests.c\
							read_key.c
	LINE_EDITION_DIR =		line_edition/
	LINE_EDITION = 			${addprefix $(LINE_EDITION_DIR), $(LINE_EDITION_SRC)}

	PARSER_LEXER_SRC =
	PARSER_LEXER_DIR =		parser_lexer/
	PARSER_LEXER	 =		${addprefix $(PARSER_LEXER_DIR), $(PARSER_LEXER_SRC)}

#main sources
SRC_DIR =			./sources/
SRC =				${addprefix $(SRC_DIR), $(SRC_NAME)}

#objects
OBJ_NAME =		$(SRC_NAME:.c=.o)
OBJ_DIR =		./objects/
OBJ =			${addprefix $(OBJ_DIR), $(OBJ_NAME)}

#object sub-directories
ALL_OBJ_DIR =	$(OBJ_DIR)$(LINE_EDITION_DIR)\
				$(OBJ_DIR)$(LEXER_PARSER_DIR)

###### HEADERS ########

HEADER_DIR =	./includes/
HEADER_NAME =	21sh.h\
				line_edit.h
HEADER =		${addprefix $(HEADER_DIR), $(HEADER_NAME)}

#######  LIBS  ########

LIB_NAME =		haflib.a
LIB_DIR =		./haflib/
LIB_HEADER =	./haflib/includes/
LIB =			${addprefix $(LIB_DIR), $(LIB_NAME)}

#######  MISC  ########

FLAGS =			-Wall -Werror -Wextra -g3 -ltermcap
DEBUG_FLAGS =	$(FLAGS) -O0 -fsanitize=address
CC =			clang

#################################################################################
##################################### RULES #####################################
#################################################################################

.PHONY: all clean fclean re lre
.SILENT:

########## GENERALS ##########

all: ./auteur $(LIB) $(OBJ_DIR) $(NAME) $(HEADER)

re: fclean all

lre:
	rm -r $(OBJ_DIR)
	make all

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean:
	make fclean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR) $(NAME) *.dSYM
	echo "\033[31m\033[1m\033[4mCleaning\033[0m\033[31m : Everything\033[0m [$(NAME)]";

debug:
	rm -r $(OBJ_DIR)
	make $(NAME)_debug

######### COMPILATION #########

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME) -I$(HEADER_DIR) -I$(LIB_DIR)
	echo "\n \033[1m\033[4m\033[35m\\^/ Done compiling \\^/\033[0m [$(NAME)] --> $(LIB_NAME)"
	make header_print

$(NAME)_debug: ./auteur $(LIB) $(OBJ_DIR) $(HEADER) $(OBJ)
	$(CC) $(DEBUG_FLAGS) $(OBJ) $(LIB) -o $(NAME) -I$(HEADER_DIR) -I$(LIB_DIR)
	echo "\n \033[1m\033[4m\033[35m\\^/ Done compiling \\^/\033[0m [$(NAME)] --> $(LIB_NAME)"
	make header_print

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEADER_DIR) -I$(LIB_HEADER)
	printf "\033[32m\033[1m\033[4mCompiling\033[0m\033[32m : %-30s \033[0m [$(NAME)]\n" $@

$(OBJ_DIR): $(ALL_OBJ_DIR)
	mkdir -p $(OBJ_DIR)
	echo "\033[32m\033[1m\033[4mCreated\033[0m\033[32m : general obj dir\033[0m"

$(ALL_OBJ_DIR):
	mkdir -p $@
	echo "\033[32m\033[1m\033[4mCreated\033[0m\033[32m : $@ obj dir\033[0m"

./auteur:
	echo $(AUTEUR) > ./auteur
	echo "\033[32m<Created Author file>\033[0m"

header_print:
	clear
	echo "Wow that's done"

############# LIB #############

$(LIB):
	make -C $(LIB_DIR)
