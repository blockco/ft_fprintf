/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:51:43 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/18 14:16:25 by rpassafa         ###   ########.us       */
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
		&& tempflag->hh == 0)
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
