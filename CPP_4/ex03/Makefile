NAME = materia

SRC = ./AMateria.cpp ./Character.cpp ./Cure.cpp ./Ice.cpp ./MateriaSource.cpp ./main.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ./AMateria.hpp ./Character.hpp ./ICharacter.hpp ./Cure.hpp ./Ice.hpp ./MateriaSource.hpp ./IMateriaSource.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
