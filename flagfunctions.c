/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:51:43 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/14 06:12:19 by rpassafa         ###   ########.us       */
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

// void flagformating(s_flags **flag)
// {
// 	s_flags *tempflag;
// 	tempflag = *flag;
//
// }
