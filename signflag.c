#include "ft_printf.h"

char *signflagextend(char *temp, s_flags *tempflag, int size, int zero, char *str, char *buffer)
{
	size = ft_strlen(temp);
	if (str[0] == '-')
		temp = ft_strsub((char const*)temp, 1, ft_strlen(temp));
	else
	{
		temp = ft_strsub((char const*)temp, 0, ft_strlen(temp));
		size++;
	}
	if ((tempflag->sign - size) > 0 && (tempflag->zero == 0 || (tempflag->precision > 0 || tempflag->precision == -1)))
		buffer = makespace((tempflag->sign - size), ' ');
	else if (tempflag->zero == -1)
	{
		buffer = makespace((tempflag->sign - size), '0');
		temp = betterjoin(buffer,temp);
		buffer = "";
	}
	else
		buffer = "";
	if (str[0] == '-' && zero == 0 && tempflag->conid != 6 && tempflag->conid != 7
	&& tempflag->conid != 0 && tempflag->conid != 1)
		temp = betterjoin("-",temp);
	else if (zero == 0)
		temp = betterjoin("+",temp);
	return(betterjoin(buffer,temp));
}

char *signflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	int size;
	int zero;
	zero = 0;
	size = 0;
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	if (ft_strcmp(temp,"0") == 0)
		zero = 1;
	if(tempflag->sign > 0)
	{
		temp = signflagextend(temp, tempflag, size, zero, str, "");
	}
	else if (tempflag->sign == -1 && zero == 0 && tempflag->conid != 6 && tempflag->conid != 7
	&& tempflag->conid != 0 && tempflag->conid != 1)
	{
		if (str[0] == '-' && temp[0] != '-')
			temp = betterjoin("-",temp);
		else if (str[0] != '-')
			temp = betterjoin("+",temp);
	}
	return (temp);
}

char* spaceextra(char *str, char *temp, s_flags *tempflag, char *test, int size)
{
	char *buffer;
	test = NULL;
	size = 0;
	size = ft_strlen(temp);
	if (str[0] == '-')
		test = ft_strsub((char const*)temp, 1, ft_strlen(temp) - 1);
	else
		test = ft_strsub((char const*)str, 0, ft_strlen(temp));
	size++;
	if ((tempflag->space - size) > 0)
	{
		buffer = makespace((tempflag->space - size), ' ');
		if(str[0] == '-')
			temp = betterjoin("-",temp);
		else
			temp = betterjoin(" ",temp);
		temp = betterjoin(buffer,temp);
		return temp;
	}
	return (test);
}

char *spaceflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *buffer;
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	buffer = "";
	if(tempflag->space > 0)
		temp = spaceextra(str, temp, tempflag, NULL, 0);
	else if (tempflag->space == -1 && (tempflag->isnegative == 0) &&
	tempflag->conid != 8 && tempflag->conid != 9 && temp[0] != '-')
	{
		temp = betterjoin(" ",temp);
	}
	else if (tempflag->space == -1)
	{
		if (tempflag->isnegative)
			temp = betterjoin("-",temp);
		else if (tempflag->space == -1 && temp[0] != '-'&&
		tempflag->conid != 8 && tempflag->conid != 9)
			temp = betterjoin(" ",temp);
	}
	temp = betterjoin(buffer,temp);
	return (temp);
}
