# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 07:03:59 by lyanga            #+#    #+#              #
#    Updated: 2026/04/07 14:11:40 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

SRCS = main.cpp \
	   Animal.cpp \
	   Dog.cpp \
	   Cat.cpp \
	   Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp 
	$(CPP) $(CPPFLAGS) -I./ -c $< -o $@

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
