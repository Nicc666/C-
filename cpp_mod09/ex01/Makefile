SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:%.cpp=objs/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = RPN

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
	./$(NAME) "5 1 2 + 4 * + 3 -"
	@echo "Expected: 14"
	./$(NAME) "10 2 /"
	@echo "Expected: 5"

.PHONY: all clean fclean re
