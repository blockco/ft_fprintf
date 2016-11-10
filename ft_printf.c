/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:43:45 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/10 14:22:29 by rpassafa         ###   ########.us       */
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

void	setflags(s_flags **flag) //move
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

void	setsymb(s_flags **flag, int *findex, const char *format) //move
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

void	findflags(s_flags **flag, int *findex, const char *format) //move
{
	int temp;
	s_flags *tempflag;
	tempflag = *flag;
	temp = *findex;
	if ((format[temp] == 'l' && format[temp + 1] == 'l') ||
			(format[temp] == 'h' && format[temp + 1] == 'h'))
	{
		if (format[temp] == 'l' && format[temp + 1] == 'l')
			tempflag->ll = 1;
		else if (format[temp] == 'h' && format[temp + 1] == 'h')
			tempflag->hh = 1;
		temp = temp + 2;
	}
	else if (format[temp] == 'h' || format[temp] == 'l' ||
			format[temp] == 'j' || format[temp] == 'z')
	{
		if (format[temp] == 'h')
			tempflag->h = 1;
		else if (format[temp] == 'l')
			tempflag->l = 1;
		else if (format[temp] == 'j')
			tempflag->j = 1;
		else if (format[temp] == 'z')
			tempflag->z = 1;
		temp++;
	}
	*findex = temp;
	*flag = tempflag;
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
	setflags(&flag);
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
				flag->precision = findprecision(format, &findex);
			findflags(&flag, &findex, format);
			g_gl[findfunind(format[findex])](&args);
		}
		else
			ft_putchar(format[findex]);
		findex++;
	}
	va_end(args);
	return flag->precision;
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
	i = ft_printf("fuck it%-+.51hhs\n", "sup fam");
	//ft_printf("%i\n",i);
}
