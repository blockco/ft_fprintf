/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 16:11:36 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/03 21:18:09 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
libft wrapped
	handling s, i, d, c,

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

/*
MOVE!!!!!!!!!!!!!
*/

void manageformat(char const *format, int *index, va_list *args)
{
	int i;

	i = 0;
	if (format[*index] == '%')
		index++;
	else if (format[*index] == '\n')
	{
			ft_putchar('\n');
			index++;
	}
	else
		{
			while (g_format[i])
			{
				if (g_format[i] == format[*index])
				{
					g_gl[i](args);
					return ;
				}
				i++;
			}
		}
}

int findamountargs(char const *format)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ret++;
		i++;
	}
	return (ret);
}

int ft_printf(const char *format, ...)
{
//declarations
	int i;
	int findex;
	//char *str;
	va_list args;
//initalizations
	i = 0;
	findex = 0;
	va_start(args,format);
	while (format[findex])
	{
		if (format[findex] == '%')
		{
			findex++;
			i++;
		}
			manageformat(format, &findex, &args);
			findex++;
	}
	return 1;
}

int main()
{
	//void *ptr;

	//ptr = "x";
	//ft_printf("%s\n%s\n\n%s%s\n","one", "two", "three", "four");
	 //ft_printf("%s\n", "dicksssssss");
	//ft_printf("%i\n%s\n%c", 10, "hi there", 'c');
	ft_printf("%o\n", 100231);
	printf("%o\n",100231);
}
