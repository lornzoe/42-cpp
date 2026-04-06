# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 06:51:38 by lyanga            #+#    #+#              #
#    Updated: 2026/04/06 12:30:37 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-implicit-fallthrough -pedantic -ansi
RM = rm -f

SRCS = main.cpp \
       Harl.cpp

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
