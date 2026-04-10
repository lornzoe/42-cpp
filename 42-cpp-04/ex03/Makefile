NAME = ex03

SRCS = main.cpp \
	   AMateria.cpp \
	   Ice.cpp \
	   Cure.cpp \
	   Character.cpp \
	   MateriaSource.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re