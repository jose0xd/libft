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

int	main(void)
{
	puts("\n** Parte 2 - Funciones adicionales **");
	test_ft_substr();
	test_ft_strjoin();
}
