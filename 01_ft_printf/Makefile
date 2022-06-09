# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 11:22:08 by bmoll-pe          #+#    #+#              #
#    Updated: 2022/06/04 02:10:22 by bmoll-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		a_ft_printf.c	b_ft_read.c	\
			ft_putchar.c	ft_putstr.c	\
			ft_strlen.c		ft_ptoa.c	\
			ft_int.c

OBJS =		$(SRCS:.c=.o)

FLAGS =		-Werror -Wextra -Wall -c

CC = 		gcc

LIBR = 		ft_printf.h

all:		$(NAME)

%.o: %.c $(LIBR)
	$(CC) $(FLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBR)
			@ar -rcs $(NAME) $^

clean:
			@rm -f	$(OBJS)

fclean:		clean
			@rm -f	$(NAME)

re:			fclean all

.PHONY: all clean fclean re
