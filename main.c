#include "ft_printf.h"
#include <stdio.h>
int main()
{
	void *ptr;
	size_t size;
	size = 10;
	//int i;
	//unsigned long l = 12356.613489;

	ptr = "x";
	// ft_printf("%s\n%s\n\n%s%s\n","one", "two", "three", "four");
	// ft_printf("%s\n", "dicksssssss");
	// ft_printf("%i\n%s\n%c\n", 10, "hi there", 'c');
	// printf("%hhd\n", (signed char)27);
	// printf("Strings:\n");
	// const char* s = "Hello";
	// printf("\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);
	// printf("Decimal:\t%i %d %+.6i %i %.0i %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
	// i = ft_printf("fuck it%-+.51hhs\n", "sup fam");
	// ft_printf("fuck it%hhd\n", 12341);
	// i = ft_printf("fuck it%#i\n",-1923);
	// printf("%.5d\n",1923);
	// printf("%+11d\n",20);
	// ft_printf("%+11d\n",20);
	// printf("%+15dqwer\n", -20);
	// ft_putnbr(size);
	// ft_printf("%i\n",i);
	// ft_printf("%s\n", ft_itoa_base(-1923,10));
	// ft_printf("this is lit\n");
	ft_printf("%   %", "test");
	printf("%   %");
}
