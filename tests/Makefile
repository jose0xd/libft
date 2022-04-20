CFLAGS = -Wall -Wextra -Werror
PART1 = ../ctype*.c ../string*.c ../stdlib*.c

all: test-part1 test-part2
	./test-part1 && ./test-part2 && echo "" && echo " ** Todo parece bien **"

test-part1: $(PART1) test-part1.c
	gcc $(CFLAGS) $(PART1) test-part1.c -o test-part1

test-part2: ../*.c test-part2.c
	gcc $(CFLAGS) ../*.c test-part2.c -o test-part2

clean:
	rm -f test-part1 test-part2
