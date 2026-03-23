# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 06:50:18 by lyanga            #+#    #+#              #
#    Updated: 2026/03/24 06:51:23 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp \
       Weapon.cpp \
       HumanA.cpp \
       HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
