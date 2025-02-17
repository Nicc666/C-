SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:%.cpp=objs/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

objs/%.o: %.cpp
	mkdir -p objs;
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME) $(shell shuf -i 1-1000 -n 3000 | tr "\n" " ")

.PHONY: all clean fclean re
