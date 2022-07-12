# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 11:22:08 by bmoll-pe          #+#    #+#              #
#    Updated: 2022/07/12 23:26:38 by bmoll-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		ft_printf/a_ft_printf.c	ft_printf/ft_putchar.c		\
			ft_printf/b_ft_read.c	ft_printf/ft_putstr.c		\
			ft_printf/ft_itoa.c		ft_printf/ft_strlen.c		\
			ft_printf/ft_ptoa.c		ft_printf/ft_uitoa.c		\
			ft_printf/ft_10to16.c

 BNS_SRCS =	ft_printf_bonus/a_ft_printf_bonus.c	ft_printf_bonus/ft_putchar_bonus.c		\
			ft_printf_bonus/b_ft_read_bonus.c	ft_printf_bonus/ft_putstr_bonus.c		\
			ft_printf_bonus/ft_itoa_bonus.c		ft_printf_bonus/ft_strlen_bonus.c		\
			ft_printf_bonus/ft_ptoa_bonus.c		ft_printf_bonus/ft_uitoa_bonus.c		\
			ft_printf_bonus/ft_10to16_bonus.c

OBJS =		$(SRCS:.c=.o)

BNS_OBJS =	$(BNS_SRCS:.c=.o)

FLAGS =		-Werror -Wextra -Wall -c

CC = 		gcc

LIBR = 		ft_printf/ft_printf.h

all:		$(NAME)

%.o: %.c $(LIBR)
	$(CC) $(FLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBR)
			@ar -rcs $(NAME) $^

bonus:		$(BNS_OBJS) $(LIBR)
			@ar -rcs $(NAME) $^

clean:
			@rm -f	$(OBJS)

fclean:		clean
			@rm -f	$(NAME)

re:			fclean all

.PHONY: all clean fclean re
