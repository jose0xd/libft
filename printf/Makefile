CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_pututils.c ft_printf_chars.c\
	  ft_printf_nums.c ft_printf_eval.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)

LIB_DIR = ..
LIB = libft.a

all: $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	@rm -f $(OBJ)

re: clean all

.PHONY: all clean re
