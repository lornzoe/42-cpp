# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 07:12:35 by lyanga            #+#    #+#              #
#    Updated: 2026/04/07 14:11:40 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(OBJS)

$(OBJS): %.o: %.cpp 
	$(CPP) $(CPPFLAGS) -I./ -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: fclean all
