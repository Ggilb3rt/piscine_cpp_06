#Coucou


NAME = scalar
FLAGS = -Wall -Wextra -Werror -g
STD = -std=c++98
COMPIL = c++
SRC = $(shell find '.' -name '*.cpp')
OBJ = $(SRC:.cpp=.o)


%.o: %.cpp
	$(COMPIL) $(FLAGS) $(STD) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPIL) $(FLAGS) $(STD) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

shrubbery_clean: fclean
	rm *_shrubbery

re: fclean all

test : all
	./$(NAME)
	./$(NAME) 234 234 1 8
	./$(NAME) ""
	./$(NAME) 7
	./$(NAME) 42.042
	./$(NAME) 8400.5e-2
	./$(NAME) -inf
	./$(NAME) c

test_leaks : all
	valgrind --leak-check=full ./$(NAME)

.PHONY : all re fclean clean test test_leaks