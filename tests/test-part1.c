#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
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

void	test_ft_strlen(void)
{
	char	str1[] = "";
	char	str2[] = "bacon frito\n";

	//printf("ft_strlen(str1): %d\n", ft_strlen(str1));
	assert(ft_strlen(str1) == strlen(str1));
	//printf("ft_strlen(str2): %d\n", ft_strlen(str2));
	assert(ft_strlen(str2) == strlen(str2));
	puts("ft_strlen: OK");
}

void	test_ft_memset(void)
{
	char	str[] = "----------";
	char	strb[] = "----------";
	
	ft_memset(str, 'z', 4);
	memset(strb, 'z', 4);
	assert(!strcmp(str, strb));
	puts("ft_memset: OK");
}

void	test_ft_bzero(void)
{
	char	str[] = "----------";
	char	strb[] = "----------";
	
	ft_bzero(str, 4);
	bzero(strb, 4);
	assert(!strcmp(str, strb));
	puts("ft_bzero: OK");
}

void	test_ft_memcpy(void)
{
	char	dst[] = "----------";
	char	dstb[] = "----------";
	char	src[] = "12345678";
	char	srcb[] = "12345678";

	ft_memcpy(dst, src, 0);	
	memcpy(dstb, srcb, 0);	
	assert(!strcmp(dst, dstb));
	ft_memcpy(dst, src, 4);	
	memcpy(dstb, srcb, 4);	
	assert(!strcmp(dst, dstb));
	puts("ft_memcpy: OK");
}

void	test_ft_memmove(void)
{
	char	str[] = "-----12345678--------";
	char	strb[] = "-----12345678--------";

	ft_memmove(str, &str[5], 0);	
	memmove(strb, &strb[5], 0);	
	assert(!strcmp(str, strb));
	ft_memmove(str, &str[5], 7);	
	memmove(strb, &strb[5], 7);	
	assert(!strcmp(str, strb));
	ft_memmove(&str[10], &str[5], 7);	
	memmove(&strb[10], &strb[5], 7);	
	assert(!strcmp(str, strb));
	puts("ft_memmove: OK");
}

void	test_ft_strlcpy(void)
{
	char	str1[] = "";
	char	str2[] = "bacon frito";
	char	str3[10];
	char	str3b[10];
	char	str4[20];
	char	str4b[20];

	int	len = ft_strlcpy(str3, str1, 10);
	//printf("ft_strlcpy(str3, str1, 10): %d\n%s\n", len, str3);
	int	lenb = strlcpy(str3b, str1, 10);
	//printf("strlcpy(str3b, str1, 10): %d\n%s\n", lenb, str3b);
	assert(len == lenb);
	assert(!strcmp(str3, str3b));

	len = ft_strlcpy(str3, str2, 10);
	//printf("ft_strlcpy(str3, str2, 10): %d\n%s\n", len, str3);
	lenb = strlcpy(str3b, str2, 10);
	//printf("strlcpy(str3b, str2, 10): %d\n%s\n", lenb, str3b);
	assert(len == lenb);
	assert(!strcmp(str3, str3b));

	len = ft_strlcpy(str4, str2, 20);
	//printf("ft_strlcpy(str4, str2, 20): %d\n%s\n", len, str4);
	lenb = strlcpy(str4b, str2, 20);
	//printf("strlcpy(str4b, str2, 20): %d\n%s\n", lenb, str4b);
	assert(len == lenb);
	assert(!strcmp(str4, str4b));
	puts("ft_strlcpy: OK");
}

void	test_ft_strlcat(void)
{
	char	str1[] = "";
	char	str2[] = "bacon frito";
	char	str3[10] = "dst.";
	char	str3b[10] = "dst.";
	char	str4[20] = "dst2.";
	char	str4b[20] = "dst2.";

	int	len = ft_strlcat(str3, str1, 10);
	//printf("ft_strlcat(str3, str1, 10): %d\n%s\n", len, str3);
	int	lenb = strlcat(str3b, str1, 10);
	//printf("strlcat(str3b, str1, 10): %d\n%s\n", lenb, str3b);
	assert(len == lenb);
	assert(!strcmp(str3, str3b));

	len = ft_strlcat(str3, str1, 2);
	//printf("ft_strlcat(str3, str1, 2): %d\n%s\n", len, str3);
	lenb = strlcat(str3b, str1, 2);
	//printf("strlcat(str3b, str1, 2): %d\n%s\n", lenb, str3b);
	assert(len == lenb);
	assert(!strcmp(str3, str3b));

	len = ft_strlcat(str3, str2, 10);
	//printf("ft_strlcat(str3, str2, 10): %d\n%s\n", len, str3);
	lenb = strlcat(str3b, str2, 10);
	//printf("strlcat(str3b, str2, 10): %d\n%s\n", lenb, str3b);
	assert(len == lenb);
	assert(!strcmp(str3, str3b));

	len = ft_strlcat(str4, str2, 20);
	//printf("ft_strlcat(str4, str2, 20): %d\n%s\n", len, str4);
	lenb = strlcat(str4b, str2, 20);
	//printf("strlcat(str4b, str2, 20): %d\n%s\n", lenb, str4b);
	assert(len == lenb);
	assert(!strcmp(str4, str4b));
	puts("ft_strlcat: OK");
}

void	test_ft_strchr(void)
{
	char	str[] = "string de muestra.";
	/*
	puts(str);
	printf("ft_strchr(str, 'e'): %p\n", ft_strchr(str, 'e'));
	printf("strchr(str, 'e'):    %p\n", strchr(str, 'e'));
	printf("ft_strchr(str, 'z'): %p\n", ft_strchr(str, 'z'));
	printf("strchr(str, 'z'):    %p\n", strchr(str, 'z'));
	printf("ft_strchr(str, '\\0'): %p\n", ft_strchr(str, '\0'));
	printf("strchr(str, '\\0'):    %p\n", strchr(str, '\0'));
	*/
	assert(ft_strchr(str, 'e') == strchr(str, 'e'));
	assert(ft_strchr(str, 'z') == strchr(str, 'z'));
	assert(ft_strchr(str, '\0') == strchr(str, '\0'));
	puts("ft_strchr: OK");
}

void	test_ft_strrchr(void)
{
	char	str[] = "string de muestra.";
	/*
	puts(str);
	printf("ft_strrchr(str, 'e'): %p\n", ft_strrchr(str, 'e'));
	printf("strrchr(str, 'e'):    %p\n", strrchr(str, 'e'));
	printf("ft_strrchr(str, 'z'): %p\n", ft_strrchr(str, 'z'));
	printf("strrchr(str, 'z'):    %p\n", strrchr(str, 'z'));
	printf("ft_strrchr(str, '\\0'): %p\n", ft_strrchr(str, '\0'));
	printf("strrchr(str, '\\0'):    %p\n", strrchr(str, '\0'));
	*/
	assert(ft_strrchr(str, 'e') == strrchr(str, 'e'));
	assert(ft_strrchr(str, 'z') == strrchr(str, 'z'));
	assert(ft_strrchr(str, '\0') == strrchr(str, '\0'));
	puts("ft_strrchr: OK");
}

void	test_ft_strncmp(void)
{
	char	*str1 = "Un string\n";
	char	*str2 = "Un string\nx";
	char	*str3 = "Un strzn\n";
	char	*str4 = "Un strang\n";

	assert(ft_strncmp(str1, str2, 30) == strncmp(str1, str2, 30));
	assert(ft_strncmp(str1, str3, 30) == strncmp(str1, str3, 30));
	assert(ft_strncmp(str1, str4, 30) == strncmp(str1, str4, 30));
	assert(ft_strncmp(str1, str4, 6) == strncmp(str1, str4, 6));
	puts("ft_strncmp: OK");
}

void	test_ft_memchr(void)
{
	char	str[] = "string de muestra.";
	char	str2[6] = {'a', 'b', '\0', 'c', 'd', '\0'};
	/*
	puts(str);
	printf("ft_memchr(str, 'e', 16): %p\n", ft_memchr(str, 'e', 16));
	printf("memchr(str, 'e', 16):    %p\n", memchr(str, 'e', 16));
	printf("ft_memchr(str, 'z', 32): %p\n", ft_memchr(str, 'z', 32));
	printf("memchr(str, 'z', 32):    %p\n", memchr(str, 'z', 32));
	printf("ft_memchr(str, '\\0', 32): %p\n", ft_memchr(str, '\0', 32));
	printf("memchr(str, '\\0', 32):    %p\n", memchr(str, '\0', 32));
	printf("ft_memchr(str2, 'c', 6): %p\n", ft_memchr(str2, 'c', 6));
	printf("memchr(str2, 'c', 6):    %p\n", memchr(str2, 'c', 6));
	*/
	assert(ft_memchr(str, 'e', 16) == memchr(str, 'e', 16));
	assert(ft_memchr(str, 'e', 6) == memchr(str, 'e', 6));
	assert(ft_memchr(str, 'z', 32) == memchr(str, 'z', 32));
	assert(ft_memchr(str, '\0', 32) == memchr(str, '\0', 32));
	assert(ft_memchr(str2, 'c', 6) == memchr(str2, 'c', 6));
	puts("ft_memchr: OK");
}

void	test_ft_memcmp(void)
{
	char	*str1 = "Un string\n";
	char	*str2 = "Un string\nx";
	char	*str3 = "Un strzn\n";
	char	*str4 = "Un strang\n";

	assert(ft_memcmp(str1, str2, 10) == memcmp(str1, str2, 10));
	assert(ft_memcmp(str1, str3, 15) == memcmp(str1, str3, 15));
	assert(ft_memcmp(str1, str4, 10) == memcmp(str1, str4, 10));
	assert(ft_memcmp(str1, str4, 6) == memcmp(str1, str4, 6));
	puts("ft_memcmp: OK");
}

void	test_ft_strnstr(void)
{
	char	haystack[] = "Un string para buscar.";
	char	ndl1[] = "";
	char	ndl2[] = " para";
	char	ndl3[] = "perita";
	char	ndl4[] = "buscar..";

	assert(ft_strnstr(haystack, ndl1, 30) == strnstr(haystack, ndl1, 30));
	assert(ft_strnstr(haystack, ndl2, 12) == strnstr(haystack, ndl2, 12));
	assert(ft_strnstr(haystack, ndl2, 20) == strnstr(haystack, ndl2, 20));
	assert(ft_strnstr(haystack, ndl3, 25) == strnstr(haystack, ndl3, 25));
	assert(ft_strnstr(haystack, ndl4, 30) == strnstr(haystack, ndl4, 30));
	puts("ft_strnstr: OK");
}

void	test_ft_strdup(void)
{
	char	*str = "Doble elefante telepata de guerra.";
	char	*cpy;
	char	*cpy2;

	cpy = ft_strdup(str);
	cpy2 = strdup(str);
	assert((cpy == 0 || cpy2 == 0 ? cpy == cpy2 : !strcmp(cpy, cpy2)));
	puts("ft_strdup: OK");
}

void	test_ft_atoi(void)
{
	char	*str1 = "  +235";
	char	*str2 = " \t-62fa";
	char	*str3 = "6246% ";
	char	*str4 = "987654321098";

	assert(ft_atoi(str1) == atoi(str1));
	assert(ft_atoi(str2) == atoi(str2));
	assert(ft_atoi(str3) == atoi(str3));
	assert(ft_atoi(str4) == atoi(str4));
	puts("ft_atoi: OK");
}

void	test_ft_calloc(void)
{
	//void	*ptr1;
	//void	*ptr2;

	assert(!memcmp(ft_calloc(5, 4), calloc(5, 4), 5*4));
	assert(!memcmp(ft_calloc(0, 4), calloc(0, 4), 0*4));
	puts("ft_calloc: OK");
}

int	main(void)
{
	puts("** ctype.h **");
	test_ctype();
	puts("\n** string.h **");
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_strdup();
	puts("\n** stdlib.h");
	test_ft_atoi();
	test_ft_calloc();
}
