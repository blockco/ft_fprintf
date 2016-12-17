/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:51:43 by rpassafa          #+#    #+#             */
/*   Updated: 2016/12/16 23:01:39 by rpassafa         ###   ########.us       */
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
		tempflag->hash == 0 && tempflag->zero == 0 && tempflag->mflag == 0 &&
		tempflag->extra == 0 && tempflag->precision == 0)
		return 1;
	return 0;
}
