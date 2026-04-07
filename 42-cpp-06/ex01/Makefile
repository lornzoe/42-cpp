# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 07:11:14 by lyanga            #+#    #+#              #
#    Updated: 2026/04/07 14:11:40 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Serializer.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJS): %.o: %.cpp 
	$(CPP) $(CPPFLAGS) -I./ -c $< -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
