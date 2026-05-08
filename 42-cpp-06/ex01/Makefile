# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 07:11:14 by lyanga            #+#    #+#              #
#    Updated: 2026/05/08 11:52:44 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Serializer.cpp main.cpp
DEPS = Serializer.hpp Data.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJS): %.o: %.cpp $(DEPS)
	$(CPP) $(CPPFLAGS) -I./ -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
