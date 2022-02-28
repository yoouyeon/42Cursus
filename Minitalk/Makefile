# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 11:56:39 by jeyoon            #+#    #+#              #
#    Updated: 2022/02/26 00:30:26 by jeyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_CLIENT = client.c
SRCS_SERVER = server.c
OBJS_CLIENT = client.o
OBJS_SERVER = server.o
SRCS_UTIL = util.c
OBJS_UTIL = util.o
SERVER = server
CLIENT = client
NAME = minitalk

all: $(NAME)

$(NAME): server client

server: $(OBJS_SERVER) $(OBJS_UTIL)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(OBJS_UTIL)

client: $(OBJS_CLIENT) $(OBJS_UTIL)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(OBJS_UTIL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS_SERVER)
	rm -rf $(OBJS_CLIENT)
	rm -rf $(OBJS_UTIL)

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all

