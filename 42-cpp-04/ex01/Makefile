# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 07:03:14 by lyanga            #+#    #+#              #
#    Updated: 2026/03/24 07:04:59 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

SRCS = main.cpp \
	   Animal.cpp \
	   Dog.cpp \
	   Cat.cpp \
	   Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
