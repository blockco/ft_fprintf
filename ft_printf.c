/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 16:11:36 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/03 12:46:05 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

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
					index++;
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
	//ft_printf("%s\n%s\n\n%s%s\n","one", "two", "three", "four");
	 //ft_printf("%s\n", "dicksssssss");
	ft_printf("%d\n%s\n%c", 10, "hi there", 'c');
}
