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

SRCS =	ft_int.c		ft_printf.c			ft_putchar_fd.c	read_input.c	\
		ft_16to10.c		ft_itoa.c			ft_putstr_fd.c					\
		ft_calloc.c		ft_itoa_unsigned.c	ft_ptoa.c		ft_strlen.c

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
