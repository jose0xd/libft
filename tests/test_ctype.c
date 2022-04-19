#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "../libft.h"

void	test_ctype_char(int c)
{
	//printf("Char: %c\n", c);
	assert(ft_isalpha(c) == isalpha(c));
	assert(ft_isdigit(c) == isdigit(c));
	assert(ft_isalnum(c) == isalnum(c));
	assert(ft_isascii(c) == isascii(c));
	assert(ft_isprint(c) == isprint(c));
	assert(ft_toupper(c) == toupper(c));
	assert(ft_tolower(c) == tolower(c));
	//printf("ft_toupper(c): %c\n", ft_toupper(c));
	//printf("ft_tolower(c): %c\n", ft_tolower(c));
}

void	test_ctype(void)
{
	test_ctype_char('a');
	test_ctype_char('Z');
	test_ctype_char('%');
	test_ctype_char(' ');
	test_ctype_char(160);
	test_ctype_char('\n');
	test_ctype_char(127);
	puts("ctype functions: OK");
}

int main()
{
	test_ctype();
}
