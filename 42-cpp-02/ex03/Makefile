NAME = bsp
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp \
       Fixed.cpp \
       Point.cpp \
       bsp.cpp

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
