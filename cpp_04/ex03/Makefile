NAME = interface
CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS =	main.cpp \
character/Character.cpp \
materia/AMateria.cpp materia/Cure.cpp materia/Ice.cpp \
materiaSource/MateriaSource.cpp

OBJ_DIR = objects
OBJS =	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re