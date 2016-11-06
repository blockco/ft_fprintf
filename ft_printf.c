/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 16:11:36 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/05 20:11:12 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //testing use

char *g_format = "sSpdDioOuUxXcC";

void (*g_gl[14])(va_list *ptr) =
{
	&pf_putstr, 	//0			s
	&pf_putstr, 	//1 		S
	NULL,			//2 		p
	&pf_putnbr, 	//3			d
	NULL, 			//4			D
	&pf_putnbr, 	//5			i
	&pf_o_handle, 	//6			o
	NULL, 			//7			O
	NULL, 			//8			u
	NULL, 			//9			U
	&pf_xlow_handle,	//10		x
	&pf_x_handle,			//11		X
	&pf_putchar, 	//12		c
	&pf_putchar, 	//13		C
};

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
	ft_printf("%X\n", 1039731);
	printf("%X\n",1039731);
}
