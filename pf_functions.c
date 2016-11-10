#include "ft_printf.h"
//s
void pf_putstr(va_list *args)
{
	char *str;
	str = va_arg(*args,char*);
	ft_putstr(str);
}
//i,d
void pf_putnbr(va_list *args)
{
	int num;
	num = va_arg(*args,int);
	ft_putnbr(num);
}
//c
void pf_putchar(va_list *args)
{
	int c;
	unsigned char temp;
	c = va_arg(*args,int);
	temp = (unsigned char)c;
	ft_putchar(c);
}
//x hex
void pf_x_handle(va_list *args)
{
	int data;
	char *str;
	data = va_arg(*args,int);
	str = ft_itoa_base(data,16);
	ft_putstr(str);
}
//x hex low
void pf_xlow_handle(va_list *args)
{
	int data;
	char *str;
	data = va_arg(*args,int);
	str = ft_itoa_baselow(data,16);
	ft_putstr(str);
}
//o octo
void pf_o_handle(va_list *args)
{
	int data;
	char *str;
	data = va_arg(*args,int);
	str = ft_itoa_base(data,8);
	ft_putstr(str);
}
//O octo
void pf_oup_handle(va_list *args)
{
	unsigned long int data;
	char *str;
	data = va_arg(*args,unsigned long int);
	str = ft_itoa_base(data,8);
	ft_putstr(str);
}
//p memory
void pf_p_handle(va_list *args)
{
	uintmax_t data;
	void *ptr;
	char *str;
	ptr = va_arg(*args,void*);
	data = ((uintmax_t)ptr);
	str = ft_itoa_baselow(data,16);
	str = ft_strjoin("0x",str);
	ft_putstr(str);
}
