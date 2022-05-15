# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 17:59:24 by jeyoon            #+#    #+#              #
#    Updated: 2022/05/15 16:10:08 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

MLX_DIR		=	./mlx/
MLX_LIB		=	libmlx.dylib
MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework AppKit -lz

SRCS		=	main.c read_map.c check_map.c draw_map.c bunny.c mem_free.c
OBJS		=	main.o read_map.o check_map.o draw_map.o bunny.o mem_free.o

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make -C $(MLX_DIR) all
			$(CC) $(CFLAGS)	$(MLX_FLAGS) -o $(NAME) $(OBJS)

%.o			:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean		:
			$(RM) $(OBJS)
			make -C $(MLX_DIR) clean

fclean		:	clean
			$(RM) $(NAME)
			$(RM) $(MLX_LIB)

re			:	fclean all

norm		:
			norminette $(SRCS) so_long.h

.PHONY		:	all clean fclean re norm