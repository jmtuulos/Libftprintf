# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 09:59:08 by smarvin           #+#    #+#              #
#    Updated: 2022/06/23 16:23:03 by jheiskan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c\
ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c\
ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c\
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
ft_strtrim.c ft_tolower.c ft_toupper.c ft_ret_last_lst.c ft_lst_add_end.c\
ft_joindel.c ft_isspace.c ft_findword.c ft_is_number.c get_next_line.c\
print_c.c ft_abs.c sp_cases.c print_format.c print_p.c print_s.c itoa_float.c\
print_diouxX.c print_f.c ft_itoa_ull.c ft_itoa_long.c ft_itoa_base.c ft_printf.c\
align.c s_format.c s_format_add.c print_xX.c

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(NAME)

debug: FLAGS += -g
debug: re

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "libftprintf.a created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -I./includes -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@echo "Removed object files"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "Removed libftprintf.a"

re: fclean all

.PHONY: all clean fclean re
