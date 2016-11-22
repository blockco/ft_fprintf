#include "ft_printf.h"
//c
void pf_putchar(va_list *args, s_flags **flag)
{
	int c;
	flag = NULL;
	unsigned char temp;
	c = va_arg(*args,int);
	temp = (unsigned char)c;
	ft_putchar(c);
}
//s
void pf_putstr(va_list *args, s_flags **flag)
{
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	str = va_arg(*args,char*);
	tempflag->size = tempflag->size + ft_strlen(str);
	ft_putstr(str);
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
		str = ft_itoa_base((int)data,10);
	else if (tempflag->zflag)
		str = ft_itoa_base((ssize_t)data,10);
	else if (tempflag->j)
		str = ft_itoa_base((intmax_t)data,10);
	else if (tempflag->ll)
		str = ft_itoa_base((long long)data,10);
	else if (tempflag->l)
		str = ft_itoa_base((long)data,10);
	else if (tempflag->h)
		str = ft_itoa_base((short)data,10);
	else if (tempflag->hh)
		str = ft_itoa_base((signed char)data,10);
	if (!checkoptions(&tempflag))
		str = (char*)flagformating(str, &tempflag);
	tempflag->size = tempflag->size + ft_strlen(str);
	ft_putstr(str);
}
//X hex
void pf_x_handle(va_list *args, s_flags **flag)
{
	void* data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_base((unsigned int)data,16);
	else if (tempflag->zflag)
		str = ft_itoa_base((ssize_t)data,16);
	else if (tempflag->j)
		str = ft_itoa_base((uintmax_t)data,16);
	else if (tempflag->ll)
		str = ft_itoa_base((unsigned long long)data,16);
	else if (tempflag->l)
		str = ft_itoa_base((unsigned long)data,16);
	else if (tempflag->h)
		str = ft_itoa_base((unsigned short)data,16);
	else if (tempflag->hh)
		str = ft_itoa_base((unsigned char)data,16);
	if (!checkoptions(&tempflag))
		str = (char*)flagformating(str, &tempflag);
	tempflag->size = tempflag->size + ft_strlen(str);
	ft_putstr(str);
}
//x hex low
void pf_xlow_handle(va_list *args, s_flags **flag)
{
	void* data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_baselow((unsigned int)data,16);
	else if (tempflag->zflag)
		str = ft_itoa_baselow((ssize_t)data,16);
	else if (tempflag->j)
		str = ft_itoa_baselow((uintmax_t)data,16);
	else if (tempflag->ll)
		str = ft_itoa_baselow((unsigned long long)data,16);
	else if (tempflag->l)
		str = ft_itoa_baselow((unsigned long)data,16);
	else if (tempflag->h)
		str = ft_itoa_baselow((unsigned short)data,16);
	else if (tempflag->hh)
		str = ft_itoa_baselow((unsigned char)data,16);
	if (!checkoptions(&tempflag))
		str = (char*)flagformating(str, &tempflag);
		tempflag->size = tempflag->size + ft_strlen(str);
	ft_putstr(str);
}
//o octo
void pf_o_handle(va_list *args, s_flags **flag)
{
	void* data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	ft_putendl("hello");
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_baselow((unsigned int)data,8);
	else if (tempflag->zflag)
		str = ft_itoa_baselow((ssize_t)data,8);
	else if (tempflag->j)
		str = ft_itoa_baselow((uintmax_t)data,8);
	else if (tempflag->ll)
		str = ft_itoa_baselow((unsigned long long)data,8);
	else if (tempflag->l)
		str = ft_itoa_baselow((unsigned long)data,8);
	else if (tempflag->h)
		str = ft_itoa_baselow((unsigned short)data,8);
	else if (tempflag->hh)
		str = ft_itoa_baselow((unsigned char)data,8);
	if (!checkoptions(&tempflag))
		str = (char*)flagformating(str, &tempflag);
	tempflag->size = tempflag->size + ft_strlen(str);
	ft_putstr(str);
}
//O octo
void pf_oup_handle(va_list *args, s_flags **flag)
{
	void* data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,void*);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_baselow((unsigned int)data,8);
	else if (tempflag->zflag)
		str = ft_itoa_baselow((ssize_t)data,8);
	else if (tempflag->j)
		str = ft_itoa_baselow((uintmax_t)data,8);
	else if (tempflag->ll)
		str = ft_itoa_baselow((unsigned long long)data,8);
	else if (tempflag->l)
		str = ft_itoa_baselow((unsigned long)data,8);
	else if (tempflag->h)
		str = ft_itoa_baselow((unsigned short)data,8);
	else if (tempflag->hh)
		str = ft_itoa_baselow((unsigned char)data,8);
	if (!checkoptions(&tempflag))
		str = (char*)flagformating(str, &tempflag);
	tempflag->size = tempflag->size + ft_strlen(str);
	ft_putstr(str);
}
//p memory
void pf_p_handle(va_list *args, s_flags **flag)
{
	void *ptr;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	ptr = va_arg(*args,void*);
	str = ft_itoa_baselow((uintmax_t)ptr,16);
	str = ft_strjoin("0x",str);
	tempflag->size = tempflag->size + ft_strlen(str);
	ft_putstr(str);
}
