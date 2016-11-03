#include "ft_printf.h"

void pf_putstr(va_list *args)
{
	char *str;
	str = va_arg(*args,char*);
	ft_putstr(str);
}

void pf_putnbr(va_list *args)
{
	int num;
	num = va_arg(*args,int);
	ft_putnbr(num);
}

void pf_putchar(va_list *args)
{
	int c;
	unsigned char temp;
	c = va_arg(*args,int);
	temp = (unsigned char)c;
	ft_putchar(c);
}
