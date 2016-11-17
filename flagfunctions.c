/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:51:43 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/17 15:38:40 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void isnegative(s_flags **flag, intmax_t data)
{
	s_flags *tempflag;
	tempflag = *flag;

	if (data < 0)
		tempflag->isnegative = 1;
	else
		tempflag->isnegative = 0;
	*flag = tempflag;
}

int checkzeroflag(s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	if (tempflag->zflag == 0 && tempflag->j == 0 &&
		tempflag->ll == 0 && tempflag->l == 0 && tempflag->h == 0
		&& tempflag->hh == 0 && tempflag->hash == 0)
		return 1;
	return 0;
}

int checkoptions(s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	if (tempflag->space == 0 && tempflag->sign == 0 &&
		tempflag->hash == 0 && tempflag->zero == 0 && tempflag->mflag == 0)
		return 1;
	return 0;
}

char *ft_stradd(char* append, char *str)
{
	char *ret;
	int i;
	int j;

	i = 0;
	j = 0;
	ret = ft_strnew(ft_strlen(append) + ft_strlen(str));
	while (ret[i])
	{
		while (append[j])
		{
			ret[i] = append[j];
			i++;
			j++;
		}
		j = 0;
		while (str[j])
		{
			ret[i] = str[j];
			i++;
			j++;
		}
	}
	return (ret);
}

char	*makespace(int size, int c)
{
	char *ret;
	int i;

	i = 0;
	ret = (char*)malloc(size+1);
	ret[size] = '\0';
	ret = (char*)ft_memset(ret,c,size);
	return (ret);
}

char *fixneg(char *str)
{
	int i;
	char temp;

	i = 0;
	while (str[i])
	{

		if (str[i] == '-' && str[0] != ' ')
		{
			temp = str[0];
			str[0] = '-';
		}
		i++;
	}
	return str;
}

char *betterjoin(char *first, char *second)
{
	char *ret;

	ret = ft_strnew(ft_strlen(first) + ft_strlen(second));
	ret = ft_strjoin(first, second);
	return (ret);
}
//
char *flagformating(char *str, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *temp = NULL;
	char *test = NULL;
	char *buffer = NULL;
	int size;
	if ((tempflag->precision > 0) && (tempflag->precision - ft_strlen(str) > 0))
	{
		// ft_putendl("################### IN Percision");
		// ft_putnbr(tempflag->precision);
		//ft_putchar('\n');
		size = ft_strlen(str);
		if (str[0] == '-')
		{
			test = ft_strsub((char const*)str, 1, ft_strlen(str) - 1);
			size--;
		}
		else
		{
			test = ft_strsub((char const*)str, 0, ft_strlen(str));
		}
		temp = makespace((tempflag->precision - size), '0');
		temp = betterjoin(temp,test);
		if (str[0] == '-')
			temp = betterjoin("-",temp);
		//ft_putendl(temp);
	}
	if ((tempflag->sign == -1) || (tempflag->sign > 0))
	{
		if (temp == NULL)
			temp = ft_strdup((const char*)str);
		if(tempflag->sign > 0)
		{
			ft_putendl("fucking here");
			size = ft_strlen(temp);
			ft_putendl(temp);
			if (str[0] == '-')
				test = ft_strsub((char const*)temp, 1, ft_strlen(temp) - 1);
			else
				test = ft_strsub((char const*)str, 0, ft_strlen(temp));
			size++;
			if ((tempflag->precision - size) > 0)
				buffer = makespace((tempflag->sign - size), ' ');
			else
				buffer = "";
			ft_putendl("here bitch");
			if (str[0] == '-')
				temp = betterjoin("-",temp);
			else
				temp = betterjoin("+",temp);
			temp = betterjoin(buffer,temp);
		}
		else if (tempflag->sign == -1)
		{
			if (tempflag->isnegative && temp[0] != '-')
				temp = betterjoin("-",temp);
			else if (!tempflag->isnegative )
				temp = betterjoin("+",temp);
		}
	}
	else if ((tempflag->space == -1) || (tempflag->space > 0))
	{
		if (temp == NULL)
			temp = ft_strdup((const char*)str);
		if(tempflag->space > 0)
		{
			size = ft_strlen(temp);
			if (str[0] == '-')
				test = ft_strsub((char const*)temp, 1, ft_strlen(temp) - 1);
			else
				test = ft_strsub((char const*)str, 0, ft_strlen(temp));
			size++;
			if ((tempflag->space - size) > 0)
				buffer = makespace((tempflag->sign - size), ' ');
			else
				buffer = "";
			ft_putendl("here bitch");
			if (str[0] == '-')
				temp = betterjoin("-",temp);
			else
				temp = betterjoin("+",temp);
			temp = betterjoin(buffer,temp);
		}
		else if (tempflag->sign == -1)
		{
			if (tempflag->isnegative)
				temp = betterjoin("-",temp);
			else
				temp = betterjoin(" ",temp);
		}
	}
	if (tempflag->mflag)
	{
		//minus left?
		return "Hello3";
	}
	else if (tempflag->zflag && tempflag->precision == 0)
	{
		//zero flag
	}
	if (tempflag->hash)
	{
		//1 check and add 0x for hex(x)
		//2 check and add 0x for octal(o)
		return "Hello4";
	}
	return temp;
}
// char *flagformating(char *str, s_flags **flag)
// {
// 	char *temp;
// 	char *test;
// 	s_flags *tempflag;
// 	tempflag = *flag;
// 	test = makespace(tempflag->space, ' ');
// 	temp = ft_strnew(ft_strlen(str) + tempflag->space);
// 	temp = ft_strjoin(test,str);
// 	return temp;
// }

// char *flagformating(char *str, s_flags **flag, long long data)
// {
// 	char *temp;
// 	char *test;
// 	s_flags *tempflag;
// 	tempflag = *flag;
//
// 	if (tempflag->space || tempflag->sign)
// 	{
// 		if (tempflag->sign)
// 			tempflag->sign =
// 	}
// 	test = makespace(tempflag->space, ' ');
// 	temp = ft_strnew(ft_strlen(str) + tempflag->space);
// 	temp = ft_strjoin(test,str);
// 	data = 0;
// 	return temp;
// }
