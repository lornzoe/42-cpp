NAME = ex04
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -ansi
RM = rm -f

SRCS = main.cpp

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
