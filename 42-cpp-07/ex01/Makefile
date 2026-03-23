NAME = ex01
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
