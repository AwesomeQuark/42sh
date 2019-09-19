# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 10:33:17 by mbonati           #+#    #+#              #
#    Updated: 2019/04/24 16:40:26 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE = ft_putendl_fd.c\
	   ft_strequ.c\
	   ft_strnew.c\
	   ft_memalloc.c\
	   ft_putnbr.c\
	   ft_striter.c\
	   ft_strnstr.c\
	   ft_memccpy.c\
	   ft_putnbr_fd.c\
	   ft_striteri.c\
	   ft_strrchr.c\
	   ft_atoi.c\
	   ft_memchr.c\
	   ft_putstr.c\
	   ft_strjoin.c\
	   ft_strsplit.c\
	   ft_bzero.c\
	   ft_memcmp.c\
	   ft_putstr_fd.c\
	   ft_strlcat.c\
	   ft_strstr.c\
	   ft_intsize.c\
	   ft_memcpy.c\
	   ft_strcat.c\
	   ft_strlen.c\
	   ft_strsub.c\
	   ft_isalnum.c\
	   ft_memdel.c\
	   ft_strchr.c\
	   ft_strmap.c\
	   ft_strtrim.c\
	   ft_isalpha.c\
	   ft_memmove.c\
	   ft_strclr.c\
	   ft_strmapi.c\
	   ft_tolower.c\
	   ft_isascii.c\
	   ft_memset.c\
	   ft_strcmp.c\
	   ft_strncat.c\
	   ft_toupper.c\
	   ft_isdigit.c\
	   ft_putchar.c\
	   ft_strcpy.c\
	   ft_strncmp.c\
	   ft_isprint.c\
	   ft_putchar_fd.c\
	   ft_strdel.c\
	   ft_strncpy.c\
	   ft_isspace.c\
	   ft_putendl.c\
	   ft_strdup.c\
	   ft_strnequ.c\
	   ft_itoa.c\
	   ft_strlowcase.c\
	   ft_strupcase.c\
	   ft_strndup.c\
	   ft_lstnew.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_memdup.c\
	   ft_lstadd.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_lstaddend.c\
	   ft_strjoinfree.c\
	   get_next_line.c\
	   ft_itoa_base.c\
	   ft_putstr_space.c\
	   ft_putnbr_space.c\
	   ft_putnbr_endl.c\
	   ft_putnstr.c\
	   ft_putstr_space_end.c\
	   ft_putnbr_space_end.c\
	   new_set.c\
	   ft_strcpy_end.c\
	   ft_tab_del.c\
	   ft_add_tab.c\
	   ft_tab_size.c\
	   ft_del_line_tab.c\
	   ft_strlen_chr.c\
	   ft_tab_copy.c\
	   ft_strsplit_set.c\
	   ft_strsplit_keep.c\
	   ft_tab_to_str.c

OBJET = $(FILE:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -g3 -Werror

all: $(NAME)

$(OBJET): libft.h

$(NAME): $(OBJET)
	ar rc $(NAME) $(OBJET)
	ranlib $(NAME)

clean:
	rm -rf $(OBJET)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS)
	@printf "\033[32m\033[1m\033[4mCompiling\033[0m\033[32m : %-35s\033[0m [$(NAME)]\n" $@

.PHONY: clean re fclean all
.SILENT:
