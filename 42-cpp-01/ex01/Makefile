# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 06:32:37 by lyanga            #+#    #+#              #
#    Updated: 2026/04/06 16:50:39 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp \
       Zombie.cpp \
       zombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJS): %.o: %.cpp
	$(CPP) $(CPPFLAGS) -I./ -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
