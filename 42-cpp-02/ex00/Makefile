# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 06:54:17 by lyanga            #+#    #+#              #
#    Updated: 2026/03/24 06:54:17 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp \
       Fixed.cpp

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
