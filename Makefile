# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncella <ncella@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 11:51:38 by psens             #+#    #+#              #
#    Updated: 2017/11/29 17:25:20 by psens            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

HEAD = includes

FLAGS = -Werror -Wall -Wextra

FT_SRC = srcs/main.c srcs/ft_isvalid.c\
		 srcs/ft_setfield.c srcs/ft_getfield_w.c srcs/ft_sqrt.c\
		 srcs/ft_strreplace.c srcs/ft_fillit.c\
		 srcs/ft_tablen.c srcs/ft_strcleaner.c

LIB_SRC = libft/ft_isupper.c libft/ft_putstr.c libft/ft_memalloc.c\
		  libft/ft_strlen.c libft/ft_strsplit.c libft/ft_strsub.c\
		  libft/ft_strncpy.c\

LIB_OBJ = ft_isupper.o ft_putstr.o ft_memalloc.o ft_strlen.o ft_strsplit.o\
		  ft_strsub.o ft_strncpy.o

all: $(NAME)

$(NAME):
	@gcc -c -I$(HEAD) $(LIB_SRC) $(FLAGS)
	@ar rc $(LIB) $(LIB_OBJ)
	@gcc -I$(HEAD) $(FT_SRC) -L. -lft -o $(NAME) $(FLAGS)

clean:
	@/bin/rm -f $(LIB_OBJ)

fclean: clean
	@/bin/rm -f $(NAME) $(LIB)

re: fclean $(NAME)

.PHONY: all clean fclean re
