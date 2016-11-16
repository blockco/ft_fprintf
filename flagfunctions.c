/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:51:43 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/16 00:25:45 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int checkzeroflag(s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	if (tempflag->z == 0 && tempflag->j == 0 &&
		tempflag->ll == 0 && tempflag->l == 0 && tempflag->h == 0
		&& tempflag->hh == 0 && tempflag->hash == 0 && tempflag->zflag == 0)
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

char *flagformating(char *str, s_flags **flag, long long data)
{
	char *temp;
	char *test;
	s_flags *tempflag;
	tempflag = *flag;
	test = makespace(tempflag->space, ' ');
	temp = ft_strnew(ft_strlen(str) + tempflag->space);
	temp = ft_strjoin(test,str);
	data = 0;
	return temp;
}

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
