# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 00:34:11 by jeyoon            #+#    #+#              #
#    Updated: 2022/07/28 00:40:53 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	=	serialization
CXX	=	c++
SRCS	=	main.cpp Serialization.cpp
OBJS	=	$(SRCS:.cpp=.o)
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

# ======= Rules =======

all	:	$(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	@printf "🤩 $(BGREEN)$(NAME) was created.$(RESET)\n"


%.o	:	%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean	:
	@rm -rf $(OBJS)
	@printf "🗑 $(NAME)'s object files were removed.\n"

fclean	:	clean
	@rm -rf $(NAME)
	@printf "🗑 $(NAME) was removed.\n"

re	:	
	@make fclean
	@make all

.PHONY : all clean fclean re leaks debug

# ======= Color =======

BGREEN	=	\033[1;32m
BCYAN	=	\033[1;96m
BPURPLE	=	\033[1;35m
RESET	=	\033[0m