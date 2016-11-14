/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:51:43 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/14 10:15:44 by rpassafa         ###   ########.us       */
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

char *flagformating(char *str, s_flags **flag, long long data)
{
	char *key;
	char *temp;
	key = "-+";
	s_flags *tempflag;
	tempflag = *flag;
	if (tempflag->sign || tempflag->space)
	{
		if (tempflag->sign)
		{
			if (data < 0)
				ft_strjoin("-",str);
			else if (data > 0)
				ft_strjoin("+", str);
		}
		else if (tempflag->space)
			{
				if (data < 0)
					ft_strjoin("-",str);
				ft_putendl("got here");
			}
			temp = ft_memalloc(tempflag->space);
			ft_memset(temp,' ', tempflag->space);
			ft_strjoin(temp, str);
	}
	else
		temp = NULL;
	return str;
}
