NAME = fragtrap

SRC = ./ClapTrap.cpp ./main.cpp ./ScavTrap.cpp ./FragTrap.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ./ClapTrap.hpp ./ScavTrap.hpp ./FragTrap.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
