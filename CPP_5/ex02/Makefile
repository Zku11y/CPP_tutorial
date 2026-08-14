NAME = AForm

SRC = ./Bureaucrat.cpp ./AForm.cpp \
 ./RobotomyRequestForm.cpp \
 ./PresidentialPardonForm.cpp \
 ./ShrubberyCreationForm.cpp \
 ./main.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ./Bureaucrat.hpp ./AForm.hpp \
	./RobotomyRequestForm.hpp ./PresidentialPardonForm.hpp ./ShrubberyCreationForm.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

