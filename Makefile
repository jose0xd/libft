CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ctype-1.c ctype-2.c string-1.c string-2.c string-3.c stdlib-1.c\
	  more-1.c more-2.c more-3.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
