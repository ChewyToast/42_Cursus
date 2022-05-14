# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 09:32:53 by marvin            #+#    #+#              #
#    Updated: 2022/05/12 10:08:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_isalpha.c	ft_isdigit.c	\
	ft_isalnum.c	ft_isascii.c	\
	ft_isprint.c	ft_strlen.c	\
	ft_memset.c	ft_bzero.c	\
	ft_strlcpy.c	ft_toupper.c	\
	ft_tolower.c	ft_memcpy.c	\
	ft_memmove.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wextra -Wall -c

CC = gcc

$(OBJS):
	$(CC) $(FLAGS) $(SRCS)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
