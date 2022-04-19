CFLAGS = -Wall -Wextra -Werror

test-part1: ctype*.c string*.c stdlib*.c tests/test-part1.c
	gcc $(CFLAGS) ctype*.c string*.c stdlib*.c tests/test-part1.c -o test-part1

test-part2: *.c tests/test-part2.c
	gcc $(CFLAGS) *.c tests/test-part2.c -o test-part2
