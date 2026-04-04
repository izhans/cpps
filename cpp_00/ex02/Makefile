NAME = account
CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CCFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
