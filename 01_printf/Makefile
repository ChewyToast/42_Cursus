# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 11:22:08 by bmoll-pe          #+#    #+#              #
#    Updated: 2022/05/27 11:24:12 by bmoll-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		00_ft_printf.c		01_ft_read_input.c	\
			02_ft_int.c			03_ft_print_atoh.c	\
			ft_itoa_unsigned.c	ft_itoa.c			\
			ft_putchar_fd.c		ft_calloc.c			\
			ft_putstr_fd.c		ft_strlen.c

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
