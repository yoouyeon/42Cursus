# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 23:02:43 by jeyoon            #+#    #+#              #
#    Updated: 2022/03/15 15:00:31 by jeyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	arg_preprocess.c \
			arg_preprocess_utils.c \
			main.c \
			op_reverse_rotate.c \
			op_rotate.c \
			op_swap_push.c \
			sort_rotate.c \
			sort_rotate_utils.c \
			sort_utils.c \
			sort_less_five.c \
			stack.c \
			utils_std.c
OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o		:	%.c
		$(CC) $(CFLAGS)	-c $< -o $@

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all, clean, fclean, re
