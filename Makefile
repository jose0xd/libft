CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = $(shell find . -name "*.c" ! -name "*_bonus.c")
SRC_BONUS = $(shell find . -name "*_bonus.c")
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f libft.a

re: fclean all

bonus: $(NAME) $(OBJ_BONUS)
	ar r $(NAME) $(OBJ_BONUS)

.PHONY: all clean fclean re
