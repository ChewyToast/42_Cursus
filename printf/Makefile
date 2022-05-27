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

SRCS =		ft_.printf.c

OBJS =		$(SRCS:.c=.o)

FLAGS =		-Werror -Wextra -Wall -c

CC = 		gcc

LIBR = 		ft_printf.h

$(OBJS):
			$(CC) $(FLAGS) $(SRCS)

$(NAME):	$(OBJS) $(LIBR)
			@ar -rcs $(NAME) $^

all:		$(NAME)

clean:
			@rm -f	$(OBJS)

fclean:		clean
			@rm -f	$(NAME)

re:			fclean all

.PHONY: all clean fclean re
