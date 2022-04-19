CFLAGS = -Wall -Wextra -Werror

test-ctype: ctype*.c tests/test_ctype.c
	gcc $(CFLAGS) ctype*.c tests/test_ctype.c -o test-ctype

test-string: string*.c tests/test_string.c
	gcc $(CFLAGS) string*.c tests/test_string.c -o test-string
