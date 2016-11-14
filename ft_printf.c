/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:43:45 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/14 06:14:07 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //testing use

char *g_format = "sSpdDioOuUxXcC";

void (*g_gl[14])(va_list *ptr, s_flags **flag) =
{
	&pf_putstr, 	//0			s
	&pf_putstr, 	//1 		S
	&pf_p_handle,	//2 		p
	&pf_putnbr, 	//3			d
	&pf_putnbr, 	//4			D
	&pf_putnbr, 	//5			i
	&pf_o_handle, 	//6			o
	&pf_oup_handle, //7			O
	NULL, 			//8			u
	NULL, 			//9			U
	&pf_xlow_handle,//10		x
	&pf_x_handle,	//11		X
	&pf_putchar, 	//12		c
	&pf_putchar, 	//13		C
};

int findprecision(const char *format, int *findex) //move
{
	int i = 0;
	int temp;

	temp = *findex;
	temp++;
	while(format[temp] >= '0' && format[temp] <= '9')
	{

		if (format[temp + 1] >= '0' && format[temp + 1] <= '9')
		{
			i = i + format[temp] - 48;
			i = i * 10;
		}
		else
			i = i + format[temp] - 48;
		temp++;
	}
	*findex = temp;
	return i;
}

int findfunind(char c)
{
	int i;

	i = 0;
	while (g_format[i])
	{
		//printf("%i%c:%c\n",i, g_format[i], c);
		if(g_format[i] == c)
			return i;
		i++;
	}
	return -1;
}

int ft_printf(const char *format, ...)
{
	int findex;
	va_list args;
	s_flags *flag;
	flag = malloc(sizeof(s_flags));
	findex = 0;
	va_start(args,format);
	while (format[findex])
	{
		setflags(&flag);
		if (format[findex] == '%')
		{
			findex++;
			if (format[findex] == '#' || format[findex] == '0'
				|| format[findex] == '-' || format[findex] == '+')
				setsymb(&flag,&findex,format);
			ft_putnbr(flag->mflag);
			if (format[findex] == '.')
				flag->precision = findprecision(format, &findex);
			findflags(&flag, &findex, format);
			g_gl[findfunind(format[findex])](&args,&flag);
			//flagformating(&flag); //flag handling
		}
		else
			ft_putchar(format[findex]);
		findex++;
	}
	va_end(args);
	return flag->mflag;
}

int main()
{
	void *ptr;
	size_t size;
	size = 10;
	int i;
	//unsigned long l = 12356.613489;

	ptr = "x";
	// ft_printf("%s\n%s\n\n%s%s\n","one", "two", "three", "four");
	// ft_printf("%s\n", "dicksssssss");
	// ft_printf("%i\n%s\n%c\n", 10, "hi there", 'c');
	//printf("%hhd\n", (signed char)27);
	//printf("Strings:\n");
	// const char* s = "Hello";
	// printf("\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);
	// printf("Decimal:\t%i %d %+.6i %i %.0i %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
	//i = ft_printf("fuck it%-+.51hhs\n", "sup fam");
	//ft_printf("fuck it%hhd\n", 12341);
	i = ft_printf("fuck it%-20zo\n", (ssize_t)1923);
	printf("%d\n",i);
	printf("%.3dqwer\n", 20);
	//ft_putnbr(size);
	//ft_printf("%i\n",i);
}
