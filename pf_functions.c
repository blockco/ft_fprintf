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
	flag = NULL;
	str = va_arg(*args,char*);
	ft_putstr(str);
}
//i,d
void pf_putnbr(va_list *args, s_flags **flag)
{
	int num;
	s_flags *tempflag;
	tempflag = *flag;
	if (checkzeroflag(&tempflag) == 1)
		ft_putnbr(va_arg(*args,int));
	else if (tempflag->z)
		ft_putnbr(va_arg(*args,ssize_t));
	else if (tempflag->j)
		ft_putnbr(va_arg(*args,intmax_t));
	else if (tempflag->ll)
		ft_putnbr(va_arg(*args,long long));
	else if (tempflag->l)
		ft_putnbr(va_arg(*args,long));
	else if (tempflag->h)
	{
		num = va_arg(*args,int);
		ft_putnbr((short)num);
	}
	else if (tempflag->hh)
	{
		num = va_arg(*args,int);
		ft_putnbr((signed char)num);
	}
}
//X hex
void pf_x_handle(va_list *args, s_flags **flag)
{
	int data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_base(va_arg(*args,unsigned int),16);
	else if (tempflag->z)
		str = ft_itoa_base(va_arg(*args,size_t),16);
	else if (tempflag->j)
		str = ft_itoa_base(va_arg(*args,uintmax_t),16);
	else if (tempflag->ll)
		str = ft_itoa_base(va_arg(*args,unsigned long long),16);
	else if (tempflag->l)
		str = ft_itoa_base(va_arg(*args,unsigned long),16);
	else if (tempflag->h)
	{
		data = va_arg(*args,int);
		str = ft_itoa_base((unsigned short)data,16);
	}
	else if (tempflag->hh)
	{
		data = va_arg(*args,int);
		str = ft_itoa_base((unsigned char)data,16);
	}
	ft_putstr(str);
}
//x hex low
void pf_xlow_handle(va_list *args, s_flags **flag)
{
	int data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_baselow(va_arg(*args,unsigned int),16);
	else if (tempflag->z)
		str = ft_itoa_baselow(va_arg(*args,size_t),16);
	else if (tempflag->j)
		str = ft_itoa_baselow(va_arg(*args,uintmax_t),16);
	else if (tempflag->ll)
		str = ft_itoa_baselow(va_arg(*args,unsigned long long),16);
	else if (tempflag->l)
		str = ft_itoa_baselow(va_arg(*args,unsigned long),16);
	else if (tempflag->h)
	{
		data = va_arg(*args,int);
		str = ft_itoa_baselow((unsigned short)data,16);
	}
	else if (tempflag->hh)
	{
		data = va_arg(*args,int);
		str = ft_itoa_baselow((unsigned char)data,16);
	}
	ft_putstr(str);
}
//o octo
void pf_o_handle(va_list *args, s_flags **flag)
{
	int data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_baselow(va_arg(*args,unsigned int),8);
	else if (tempflag->z)
		str = ft_itoa_baselow(va_arg(*args,size_t),8);
	else if (tempflag->j)
		str = ft_itoa_baselow(va_arg(*args,uintmax_t),8);
	else if (tempflag->ll)
		str = ft_itoa_baselow(va_arg(*args,unsigned long long),8);
	else if (tempflag->l)
		str = ft_itoa_baselow(va_arg(*args,unsigned long),8);
	else if (tempflag->h)
	{
		data = va_arg(*args,int);
		str = ft_itoa_baselow((unsigned short)data,8);
	}
	else if (tempflag->hh)
	{
		data = va_arg(*args,int);
		str = ft_itoa_baselow((unsigned char)data,8);
	}
	ft_putstr(str);
}
//O octo
void pf_oup_handle(va_list *args, s_flags **flag)
{
	int data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_base(va_arg(*args,unsigned int),8);
	else if (tempflag->z)
		str = ft_itoa_base(va_arg(*args,size_t),8);
	else if (tempflag->j)
		str = ft_itoa_base(va_arg(*args,uintmax_t),8);
	else if (tempflag->ll)
		str = ft_itoa_base(va_arg(*args,unsigned long long),8);
	else if (tempflag->l)
		str = ft_itoa_base(va_arg(*args,unsigned long),8);
	else if (tempflag->h)
	{
		data = va_arg(*args,int);
		str = ft_itoa_base((unsigned short)data,8);
	}
	else if (tempflag->hh)
	{
		data = va_arg(*args,int);
		str = ft_itoa_base((unsigned char)data,8);
	}
	ft_putstr(str);
}
//p memory
void pf_p_handle(va_list *args, s_flags **flag)
{
	uintmax_t data;
	void *ptr;
	char *str;
	flag = NULL;
	ptr = va_arg(*args,void*);
	data = ((uintmax_t)ptr);
	str = ft_itoa_baselow(data,16);
	str = ft_strjoin("0x",str);
	ft_putstr(str);
}
