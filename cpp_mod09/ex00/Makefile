SRCS = main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:%.cpp=objs/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = btc

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

.PHONY: all clean fclean re
