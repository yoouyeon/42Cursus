# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 11:05:22 by jeyoon            #+#    #+#              #
#    Updated: 2022/07/11 13:57:16 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
CXX	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Contact.cpp PhoneBook.cpp utils.cpp
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

re	:	fclean all

.PHONY : all clean fclean re