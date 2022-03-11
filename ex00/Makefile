#Coucou


NAME = convert
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
	@echo "\tErrors :"
	./$(NAME)
	@echo "\n"
	./$(NAME) 234 234 1 8
	@echo "\n"
	./$(NAME) ""
	@echo "\n\n\tSubject: \n"
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	@echo "\n\n\tPerso: \n"
	./$(NAME) pouet
	./$(NAME) 7
	./$(NAME) 43.234f
	./$(NAME) 83.042
	./$(NAME) 8400.5e-2
	./$(NAME) -inf
	./$(NAME) nanf
	./$(NAME) c
	./$(NAME) 3654.4028234665465465467e+38

test_leaks : all
	valgrind --leak-check=full ./$(NAME)

.PHONY : all re fclean clean test test_leaks