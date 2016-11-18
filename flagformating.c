#include "ft_printf.h"

char *flagformating(char *str, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *temp = NULL;
	char *test = NULL;
	char *buffer = NULL;
	int size;
	if ((tempflag->precision > 0) && (tempflag->precision - ft_strlen(str) > 0))
	{
		size = ft_strlen(str);
		if (str[0] == '-')
		{
			test = ft_strsub((char const*)str, 1, ft_strlen(str) - 1);
			size--;
		}
		else
		{
			test = ft_strsub((char const*)str, 0, ft_strlen(str));
		}
		temp = makespace((tempflag->precision - size), '0');
		temp = betterjoin(temp,test);
		if (str[0] == '-')
			temp = betterjoin("-",temp);
	}
	if ((tempflag->sign == -1) || (tempflag->sign > 0))
	{
		if (temp == NULL)
			temp = ft_strdup((const char*)str);
		if(tempflag->sign > 0)
		{
			ft_putendl("fucking here");
			size = ft_strlen(temp);
			ft_putendl(temp);
			if (str[0] == '-')
				test = ft_strsub((char const*)temp, 1, ft_strlen(temp) - 1);
			else
				test = ft_strsub((char const*)str, 0, ft_strlen(temp));
			size++;
			if ((tempflag->precision - size) > 0)
				buffer = makespace((tempflag->sign - size), ' ');
			else
				buffer = "";
			ft_putendl("here bitch");
			if (str[0] == '-')
				temp = betterjoin("-",temp);
			else
				temp = betterjoin("+",temp);
			temp = betterjoin(buffer,temp);
		}
		else if (tempflag->sign == -1)
		{
			if (tempflag->isnegative && temp[0] != '-')
				temp = betterjoin("-",temp);
			else if (!tempflag->isnegative )
				temp = betterjoin("+",temp);
		}
	}
	else if ((tempflag->space == -1) || (tempflag->space > 0))
	{
		if (temp == NULL)
			temp = ft_strdup((const char*)str);
		if(tempflag->space > 0)
		{
			size = ft_strlen(temp);
			if (str[0] == '-')
				test = ft_strsub((char const*)temp, 1, ft_strlen(temp) - 1);
			else
				test = ft_strsub((char const*)str, 0, ft_strlen(temp));
			size++;
			if ((tempflag->space - size) > 0)
				buffer = makespace((tempflag->sign - size), ' ');
			else
				buffer = "";
			ft_putendl("here bitch");
			if (str[0] == '-')
				temp = betterjoin("-",temp);
			else
				temp = betterjoin("+",temp);
			temp = betterjoin(buffer,temp);
		}
		else if (tempflag->space == -1 && (tempflag->isnegative == 0))
			temp = betterjoin(" ",temp);
		else if (tempflag->sign == -1)
		{
			if (tempflag->isnegative)
				temp = betterjoin("-",temp);
			else
				temp = betterjoin(" ",temp);
		}
	}
	if (tempflag->mflag)
	{
		int size;
		char *buffer;
		if (temp == NULL)
			temp = ft_strdup((const char*)str);
		size = tempflag->mflag - ft_strlen(temp);
		if (size > 0)
		{
			buffer = makespace(size, ' ');
			temp = betterjoin(temp,buffer);
		}
	}
	else if (tempflag->zero && tempflag->precision == 0)
	{
		int size;
		char *buffer;
		if (temp == NULL)
			temp = ft_strdup((const char*)str);
		size = tempflag->zero - ft_strlen(temp);
		if (size > 0)
		{
			buffer = makespace(size, '0');
			temp = betterjoin(temp,buffer);
		}
	}
	if (tempflag->hash && (tempflag->conid == 6 || tempflag->conid == 7
	|| tempflag->conid == 11 || tempflag->conid == 10))
	{
		int size;

		if (temp == NULL)
			temp = ft_strdup((const char*)str);
		if ((tempflag->conid == 6 || tempflag->conid == 7) && (temp[0] != '0'))
			temp = betterjoin("0", temp);
		else if ((tempflag->conid == 10 || tempflag->conid == 11) &&
		(temp[0] != '0' && temp[1] != 'x'))
			temp = betterjoin("0x", temp);
		size = tempflag->hash - ft_strlen(temp);
		if (size > 0)
		{
			buffer = makespace(size, ' ');
			temp = betterjoin(buffer, temp);
		}

	}
	return temp;
}
