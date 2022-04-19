CFLAGS = -Wall -Wextra -Werror

test-part1: ctype*.c string*.c stdlib*.c tests/test-part1.c
	gcc $(CFLAGS) ctype*.c string*.c stdlib*.c tests/test-part1.c -o test-part1

