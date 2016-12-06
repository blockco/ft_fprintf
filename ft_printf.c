/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:43:45 by rpassafa          #+#    #+#             */
/*   Updated: 2016/12/04 22:35:27 by rpassafa         ###   ########.us       */
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
	&pf_u_handle,	//8			u
	&pf_u_handle, 	//9			U
	&pf_xlow_handle,//10		x
	&pf_x_handle,	//11		X
	&pf_putchar, 	//12		c
	&pf_putchar, 	//13		C
};

int findfunind(char c)
{
	int i;

	i = 0;
	while (g_format[i])
	{
		if(g_format[i] == c)
			return i;
		i++;
	}
	return -1;
}

// int ft_printf(const char *format, ...)
// {
// 	int findex;
// 	va_list args;
// 	s_flags *flag;
// 	flag = malloc(sizeof(s_flags));
// 	findex = 0;
// 	va_start(args,format);
// 	setflags(&flag);
// 	while (format[findex])
// 	{
// 		if (format[findex] == '%')
// 		{
// 			findex++;
// 			if (format[findex] == '#' || format[findex] == '0'
// 				|| format[findex] == '-' || format[findex] == '+' ||
// 				format[findex] == ' ')
// 				setsymb(&flag,&findex,format);
// 			if (format[findex] >= '0' && format[findex] <= '9')
// 				flag->extra = findprecisionextra(format, &findex);
// 			if (format[findex] == '.')
// 				flag->precision = findprecision(format, &findex);
// 			if (format[findex] == '%')
// 			{
// 				ft_putchar(format[findex]);
// 				flag->size = flag->size + 1;
// 			}
// 			findflags(&flag, &findex, format);
// 			flag->conid = findfunind(format[findex]);
// 			if (flag->conid > -1)
// 				g_gl[flag->conid](&args,&flag);
// 		}
// 		else
// 		{
// 			flag->size = flag->size + 1;
// 			ft_putchar(format[findex]);
// 		}
// 		findex++;
// 	}
// 	va_end(args);
// 	return flag->size;
// }

char *charadder(char *str, char c)
{
	char *temp;
	temp = (char*)malloc(2);
	temp[0] = c;
	temp[1] = '\0';
	return(betterjoin(str,temp));
}

int ft_printf(const char *format, ...)
{
	int findex;
	va_list args;
	s_flags *flag;
	flag = malloc(sizeof(s_flags));
	findex = 0;
	va_start(args,format);
	setflags(&flag);
	while (format[findex])
	{
	if (format[findex] == '%')
	{
		findex++;
		while (format[findex] == '#' || format[findex] == '0'
			|| format[findex] == '-' || format[findex] == '+' ||
			format[findex] == ' ' ||
			(format[findex] >= '0' && format[findex] <= '9') ||
			format[findex] == '.' ||
			(format[findex] == 'l' && format[findex + 1] == 'l') ||
			(format[findex] == 'h' && format[findex + 1] == 'h') ||
			format[findex] == 'h' || format[findex] == 'l' ||
			format[findex] == 'j' || format[findex] == 'z')
			{
				if (format[findex] == '#' || format[findex] == '0'
				|| format[findex] == '-' || format[findex] == '+' ||
				format[findex] == ' ')
				setsymb(&flag,&findex,format);
				else if (format[findex] >= '0' && format[findex] <= '9')
				flag->extra = findprecisionextra(format, &findex);
				else if (format[findex] == '.')
				flag->precision = findprecision(format, &findex);
				else if ((format[findex] == 'l' && format[findex + 1] == 'l') ||
				(format[findex] == 'h' && format[findex + 1] == 'h') ||
				format[findex] == 'h' || format[findex] == 'l' ||
				format[findex] == 'j' || format[findex] == 'z')
				findflags(&flag, &findex, format);
			}
		flag->conid = findfunind(format[findex]);
		if (format[findex] == '%')
		{
			while(format[findex])
			{
				flag->ret = charadder(flag->ret, format[findex]);
				findex++;
			}
			flag->ret = flagformating(flag->ret, &flag);
			ft_putstr(flag->ret);
			return (ft_strlen(flag->ret));
		}
		if (flag->conid > -1)
			g_gl[flag->conid](&args,&flag);

		//putstring from flag->ret
		ft_putstr(flag->ret);
		flag->size = ft_strlen(flag->ret) + flag->size;
	}
	else
	{
		flag->size = flag->size + 1;
		ft_putchar(format[findex]);
	}
	findex++;
	}
	va_end(args);
	return flag->size;
}
