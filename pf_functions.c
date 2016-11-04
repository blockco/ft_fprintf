#include "ft_printf.h"

/*

*/

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

/*
these need to be moved
	handling x, o,

*/

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

void pf_x_handle(va_list *args)
{
	int data;
	char *str;
	data = va_arg(*args,int);
	str = ft_itoa_base(data,16);
	ft_putstr(str);
}

void pf_o_handle(va_list *args)
{
	int data;
	char *str;
	data = va_arg(*args,int);
	str = ft_itoa_base(data,8);
	ft_putstr(str);
}
