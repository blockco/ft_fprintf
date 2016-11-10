/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:43:45 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/10 13:51:01 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //testing use

char *g_format = "sSpdDioOuUxXcC";

void (*g_gl[14])(va_list *ptr) =
{
	&pf_putstr, 	//0			s
	&pf_putstr, 	//1 		S
	&pf_p_handle,	//2 		p
	&pf_putnbr, 	//3			d
	NULL, 			//4			D
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

void	setflags(s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	tempflag->hh = 0;
	tempflag->h = 0;
	tempflag->l = 0;
	tempflag->ll = 0;
	tempflag->j = 0;
	tempflag->z = 0;
	tempflag->hash = 0;
	tempflag->zflag = 0;
	tempflag->mflag = 0;
	tempflag->sign = 0;
}

void	setsymb(s_flags **flag, int *findex, const char *format)
{
	int temp;
	s_flags *tempflag;
	tempflag = *flag;
	temp = *findex;
	while (format[temp] == '#' || format[temp] == '0'
		|| format[temp] == '-' || format[temp] == '+')
	{
		if (format[temp] == '#')
			tempflag->hash = 1;
		else if (format[temp] == '0')
			tempflag->zflag = 1;
		else if (format[temp] == '-')
			tempflag->mflag = 1;
		else if (format[temp] == '+')
			tempflag->sign = 1;
		temp++;
	}
	*findex = temp;
	*flag = tempflag;
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

int findprecision(const char *format, int *findex)
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

int ft_printf(const char *format, ...)
{
	int precision;
	int findex;
	int funind;
	va_list args;
	s_flags *flag;
	flag = malloc(sizeof(s_flags));
	setflags(&flag);
	precision = 0;
	findex = 0;
	va_start(args,format);
	while (format[findex])
	{
		if (format[findex] == '%')
		{
			findex++;
			if (format[findex] == '#' || format[findex] == '0'
				|| format[findex] == '-' || format[findex] == '+')
				setsymb(&flag,&findex,format);
			if (format[findex] == '.')
				precision = findprecision(format, &findex);
			if (format[findex] == 'h' && format[findex + 1] == 'h')
			{
				flag->hh = 1;
				findex = findex + 2;
			}
			else if (format[findex] == 'h')
			{
				flag->h = 1;
				findex++;
			}
			else if (format[findex] == 'l')
			{
				flag->l = 1;
				findex++;
			}
			else if (format[findex] == 'l' && format[findex + 1] == 'l')
			{
				flag->ll = 1;
				findex = findex + 2;
			}
			else if (format[findex] == 'l')
			{
				flag->l = 1;
				findex++;
			}
			else if (format[findex] == 'j')
			{
				flag->j = 1;
				findex++;
			}
			else if (format[findex] == 'z')
			{
				flag->z = 1;
				findex++;
			}
			funind = findfunind(format[findex]);
			g_gl[funind](&args);
			findex++;
		}
		else
		{
			ft_putchar(format[findex]);
			findex++;
		}
	}
	va_end(args);
	return precision;
}

int main()
{
	void *ptr;
	int i;
	//unsigned long l = 12356.613489;

	ptr = "x";
	//ft_printf("%s\n%s\n\n%s%s\n","one", "two", "three", "four");
	 //ft_printf("%s\n", "dicksssssss");
	//ft_printf("%i\n%s\n%c", 10, "hi there", 'c');
	//printf("%hhd\n", (signed char)27);
	// printf("Strings:\n");
	// const char* s = "Hello";
	// printf("\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);
	// printf("Decimal:\t%i %d %+.6i %i %.0i %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
	i = ft_printf("%-+.51hhs\n", "sup fam");
	//ft_printf("%i\n",i);
}
