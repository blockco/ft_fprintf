/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:13:53 by rpassafa          #+#    #+#             */
/*   Updated: 2016/12/05 16:27:15 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"


//c
void pf_putchar(va_list *args, s_flags **flag)
{
	int c;
	char *hold;
	s_flags *tempflag;
	tempflag = *flag;
	//unsigned char temp;
	c = va_arg(*args,int);
	tempflag->ret = charadder(tempflag->ret, 'a');
	if (!checkoptions(&tempflag))
		tempflag->ret = (char*)flagformatingstrings(tempflag->ret, &tempflag);
	hold = ft_strchr(tempflag->ret, 'a');
	hold[0] = c;
	if (c == 0)
		tempflag->size = tempflag->size + 1;
}
//s
void pf_putstr(va_list *args, s_flags **flag)
{
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	str = va_arg(*args,char*);
	tempflag->ret = ft_strdup(str);
	if (!checkoptions(&tempflag))
		tempflag->ret = (char*)flagformatingstrings(tempflag->ret, &tempflag);
}
//i,d
void pf_putnbr(va_list *args, s_flags **flag)
{
	char *str;
	void *data;

	s_flags *tempflag;
	tempflag = *flag;
	str = NULL;
	data = va_arg(*args,void*);
	isnegative(&tempflag, (long long)data);
	if (checkzeroflag(&tempflag) == 1)
		tempflag->ret = ft_itoa_base((int)data,10);
	else if (tempflag->zflag)
		tempflag->ret = ft_itoa_base((ssize_t)data,10);
	else if (tempflag->j)
		tempflag->ret = ft_itoa_baseu((uintmax_t)data,10);
	else if (tempflag->ll)
		tempflag->ret = ft_itoa_base((long long)data,10);
	else if (tempflag->l)
		tempflag->ret = ft_itoa_base((long)data,10);
	else if (tempflag->h)
		tempflag->ret = ft_itoa_base((short)data,10);
	else if (tempflag->hh)
		tempflag->ret = ft_itoa_base((signed char)data,10);
	if (!checkoptions(&tempflag))
		tempflag->ret = (char*)flagformatingstrings(tempflag->ret, &tempflag);
	}
//X hex
void pf_x_handle(va_list *args, s_flags **flag)
{
	void* data;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		tempflag->ret = ft_itoa_baseu((unsigned int)data,16);
	else if (tempflag->zflag)
		tempflag->ret = ft_itoa_base((ssize_t)data,16);
	else if (tempflag->j)
		tempflag->ret = ft_itoa_baseu((uintmax_t)data,16);
	else if (tempflag->ll)
		tempflag->ret = ft_itoa_baseu((unsigned long long)data,16);
	else if (tempflag->l)
		tempflag->ret = ft_itoa_baseu((unsigned long)data,16);
	else if (tempflag->h)
		tempflag->ret = ft_itoa_baseu((unsigned short)data,16);
	else if (tempflag->hh)
		tempflag->ret = ft_itoa_baseu((unsigned char)data,16);
	if (!checkoptions(&tempflag))
		tempflag->ret = (char*)flagformating(tempflag->ret, &tempflag);
	}
//x hex low
void pf_xlow_handle(va_list *args, s_flags **flag)
{
	void* data;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		tempflag->ret = ft_itoa_baselowu((unsigned int)data,16);
	else if (tempflag->zflag)
		tempflag->ret = ft_itoa_baselow((ssize_t)data,16);
	else if (tempflag->j)
		tempflag->ret = ft_itoa_baselowu((uintmax_t)data,16);
	else if (tempflag->ll)
		tempflag->ret = ft_itoa_baselowu((unsigned long long)data,16);
	else if (tempflag->l)
		tempflag->ret = ft_itoa_baselowu((unsigned long)data,16);
	else if (tempflag->h)
		tempflag->ret = ft_itoa_baselowu((unsigned short)data,16);
	else if (tempflag->hh)
		tempflag->ret = ft_itoa_baselowu((unsigned char)data,16);
	if (!checkoptions(&tempflag))
		tempflag->ret = (char*)flagformating(tempflag->ret, &tempflag);
	}
//o octo
void pf_o_handle(va_list *args, s_flags **flag)
{
	void* data;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		tempflag->ret = ft_itoa_baselowu((unsigned int)data,8);
	else if (tempflag->zflag)
		tempflag->ret = ft_itoa_baselow((ssize_t)data,8);
	else if (tempflag->j)
		tempflag->ret = ft_itoa_baselowu((uintmax_t)data,8);
	else if (tempflag->ll)
		tempflag->ret = ft_itoa_baselowu((unsigned long long)data,8);
	else if (tempflag->l)
		tempflag->ret = ft_itoa_baselowu((unsigned long)data,8);
	else if (tempflag->h)
		tempflag->ret = ft_itoa_baselowu((unsigned short)data,8);
	else if (tempflag->hh)
		tempflag->ret = ft_itoa_baselowu((unsigned char)data,8);
	if (!checkoptions(&tempflag))
		tempflag->ret = (char*)flagformating(tempflag->ret, &tempflag);
}
//O octo
void pf_oup_handle(va_list *args, s_flags **flag)
{
	void* data;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		tempflag->ret = ft_itoa_baselow((unsigned int)data,8);
	else if (tempflag->zflag)
		tempflag->ret = ft_itoa_baselow((ssize_t)data,8);
	else if (tempflag->j)
		tempflag->ret = ft_itoa_baselowu((uintmax_t)data,8);
	else if (tempflag->ll)
		tempflag->ret = ft_itoa_baselowu((unsigned long long)data,8);
	else if (tempflag->l)
		tempflag->ret = ft_itoa_baselowu((unsigned long)data,8);
	else if (tempflag->h)
		tempflag->ret = ft_itoa_baselowu((unsigned short)data,8);
	else if (tempflag->hh)
		tempflag->ret = ft_itoa_baselowu((unsigned char)data,8);
	if (!checkoptions(&tempflag))
		tempflag->ret = (char*)flagformating(tempflag->ret, &tempflag);
}
//p memory
void pf_p_handle(va_list *args, s_flags **flag)
{
	void *ptr;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	ptr = va_arg(*args,void*);
	str = ft_itoa_baselowu((uintmax_t)ptr,16);
	tempflag->ret = ft_strjoin("0x",str);
}
//u
void pf_u_handle(va_list *args, s_flags **flag)
{
	void* data;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		tempflag->ret = ft_itoa_baselowu((unsigned int)data,10);
	else if (tempflag->zflag)
		tempflag->ret = ft_itoa_baselow((ssize_t)data,10);
	else if (tempflag->j)
		tempflag->ret = ft_itoa_baselowu((uintmax_t)data,10);
	else if (tempflag->ll)
		tempflag->ret = ft_itoa_baselowu((unsigned long long)data,10);
	else if (tempflag->l)
		tempflag->ret = ft_itoa_baselowu((unsigned long)data,10);
	else if (tempflag->h)
		tempflag->ret = ft_itoa_baselowu((unsigned short)data,10);
	else if (tempflag->hh)
		tempflag->ret = ft_itoa_baselowu((unsigned char)data,10);
	if (!checkoptions(&tempflag))
		tempflag->ret = (char*)flagformating(tempflag->ret, &tempflag);
}
