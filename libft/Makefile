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

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c

OBJS = ${SRCS:.c=.o}

HEAD = libft.h

FLAGS = -Werror -Wextra -Wall -I $(HEAD) -c

$(NAME):	gcc $(FLAGS) 
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean: rm -f $(OBJS)

fclean: rm -f $(NAME)

re: fclean all
