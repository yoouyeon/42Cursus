# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 18:59:28 by jeyoon            #+#    #+#              #
#    Updated: 2022/07/16 16:51:03 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	=	harlFilter
CXX	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Harl.cpp
OBJS	=	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	@printf "✅ \033[0;32m$(NAME) was created.\033[0m\n"


%.o	:	%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean	:
	@rm -rf $(OBJS)
	@printf "🚮 $(NAME)'s object files were removed.\n"

fclean	:	clean
	@rm -rf $(NAME)
	@printf "🚮 $(NAME) was removed.\n"

re	:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re