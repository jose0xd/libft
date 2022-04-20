#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../libft.h"

void	test_ft_substr(void)
{
	char	*str1 = "";
	char	*str2 = "Doble elefante telepata de guerra.";

	assert(!strcmp(ft_substr(str1, 0, 3), ""));
	assert(!strcmp(ft_substr(str2, 0, 3), "Dob"));
	assert(!strcmp(ft_substr(str2, 6, 8), "elefante"));
	assert(!strcmp(ft_substr(str2, 24, 30), "de guerra."));
	puts("ft_substr: OK");
}

void	test_ft_strjoin(void)
{
	char	*str1 = "";
	char	*str2 = "Doble elefante";
	char	*str3 = " telepata de guerra.";
	char	*ptr;

	ptr = ft_strjoin(str1, str2);
	assert(!strcmp(ptr, "Doble elefante"));
	free(ptr);
	ptr = ft_strjoin(str2, str3);
	assert(!strcmp(ptr, "Doble elefante telepata de guerra."));
	free(ptr);
	ptr = ft_strjoin(ptr, str1);
	assert(!strcmp(ptr, "Doble elefante telepata de guerra."));
	free(ptr);
	puts("ft_strjoin: OK");
}

void	test_ft_strtrim(void)
{
	char	*str1 = "";
	char	*str2 = "  perita  ";
	char	*str3 = "12132perita32mas321";
	char	*ptr;

	ptr = ft_strtrim(str1, " 1");
	assert(!strcmp(ptr, ""));
	free(ptr);
	ptr = ft_strtrim(str2, " ");
	assert(!strcmp(ptr, "perita"));
	free(ptr);
	ptr = ft_strtrim(str3, "123");
	assert(!strcmp(ptr, "perita32mas"));
	free(ptr);
	puts("ft_strtrim: OK");
}

void	test_ft_split(void)
{
	char	*str1 = "";
	char	*str2 = " esto son  palabras ";
	char	**array;

	array = ft_split(str1, ' ');
	assert(array[0] == 0);
	// Dependiendo de como se construya el array de strings
	// quizás esta manera deliberarlos no funcione.
	// Borrar las lineas con free() y ya está.
	for (int i = 0; array[i]; i++)
		free(array[i]);
	free(array);
	array = ft_split(str2, ' ');
	assert(!strcmp(array[0], "esto"));
	assert(!strcmp(array[1], "son"));
	assert(!strcmp(array[2], "palabras"));
	assert(array[3] == 0);
	for (int i = 0; array[i]; i++)
		free(array[i]);
	free(array);
	puts("ft_split: OK");
}

void	test_ft_itoa(void)
{
	assert(!strcmp(ft_itoa(1234), "1234"));
	assert(!strcmp(ft_itoa(-1234), "-1234"));
	assert(!strcmp(ft_itoa(-2147483648), "-2147483648"));
	puts("ft_itoa: OK");
}

char	func(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
}

void	test_ft_strmapi(void)
{
	char	*str0 = "";
	char	*str = "Bacon Frito.";
	char	*mapi;

	mapi = ft_strmapi(str0, func);
	assert(!strcmp(mapi, ""));
	free(mapi);
	mapi = ft_strmapi(str, func);
	assert(!strcmp(mapi, "BaCoN FrItO."));
	free(mapi);
	puts("ft_strmapi: OK");
}

void	func2(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}

void	test_ft_striteri(void)
{
	char	str0[] = "";
	char	str[] = "Bacon Frito.";

	ft_striteri(str0, func2);
	assert(!strcmp(str0, ""));
	ft_striteri(str, func2);
	assert(!strcmp(str, "BaCoN FrItO."));
	puts("ft_striteri: OK");
}

void	test_ft_putchar_fd(void)
{
	printf("%s", "  Debe escribir una 'z': "),
	ft_putchar_fd('z', 1);
	puts(" OK?");
}

void	test_ft_putstr_fd(void)
{
	printf("%s", "  Debe escribir 'hola mundo': "),
	ft_putstr_fd("hola mundo", 1);
	puts(" OK?");
}

void	test_ft_putendl_fd(void)
{
	printf("%s", "  Debe escribir 'hola mundo' y \\n: "),
	ft_putendl_fd("hola mundo", 1);
	puts(" OK?");
}

void	test_ft_putnbr_fd(void)
{
	printf("%s", "  Debe escribir '1234': "),
	ft_putnbr_fd(1234, 1);
	puts(" OK?");
	printf("%s", "  Debe escribir '-1234': "),
	ft_putnbr_fd(-1234, 1);
	puts(" OK?");
	printf("%s", "  Debe escribir '-2147483648': "),
	ft_putnbr_fd(-2147483648, 1);
	puts(" OK?");
}

int	main(void)
{
	puts("\n** Parte 2 - Funciones adicionales **");
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_strmapi();
	test_ft_striteri();

	puts("");
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
}
