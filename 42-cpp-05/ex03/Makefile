# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 07:08:17 by lyanga            #+#    #+#              #
#    Updated: 2026/04/07 14:11:40 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Bureaucrat.cpp AForm.cpp Intern.cpp PresidentialPardon.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp

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
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
