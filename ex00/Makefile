CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp ScalarConverter.cpp
OBJ=$(SRC:.cpp=.o)
NAME=convert

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)