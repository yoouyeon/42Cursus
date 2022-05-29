# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 14:19:33 by jeyoon            #+#    #+#              #
#    Updated: 2022/05/29 19:08:00 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c monitoring.c philo.c utils.c init.c
OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o	:	%.c
		$(CC) $(CFLAG) -c $< -o $@

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re	:	fclean all

.PHONY	:	all, clean, fclean, re