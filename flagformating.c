#include "ft_printf.h"

char* percisionflag(char *str, char *temp, s_flags **flag)
{
	int size;
	char *test;
	s_flags *tempflag;
	tempflag = *flag;
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	size = ft_strlen(temp);
	if (temp[0] == '-')
	{
		test = ft_strsub((char const*)temp, 1, ft_strlen(temp) - 1);
		size--;
	}
	else
	{
		test = ft_strsub((char const*)temp, 0, ft_strlen(temp));
	}
	temp = makespace((tempflag->precision - size), '0');
	temp = betterjoin(temp,test);
	if (str[0] == '-')
		temp = betterjoin("-",temp);
	if (tempflag->precision == -1)
		temp = "";
	return (temp);
}

char *signflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *buffer;
	int size;
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	if(tempflag->sign > 0)
	{
		size = ft_strlen(temp);
		if (str[0] == '-')
			temp = ft_strsub((char const*)temp, 1, ft_strlen(temp));
		else
		{
			temp = ft_strsub((char const*)str, 0, ft_strlen(temp));
			size++;
		}
		if ((tempflag->sign - size) > 0 && tempflag->zero == 0)
			buffer = makespace((tempflag->sign - size), ' ');
		else if (tempflag->zero == -1)
			buffer = makespace((tempflag->sign - size), '0');
		else
			buffer = "";
		temp = betterjoin(buffer,temp);
		if (str[0] == '-')
			temp = betterjoin("-",temp);
		else
			temp = betterjoin("+",temp);
	}
	else if (tempflag->sign == -1)
	{
		if (tempflag->isnegative && temp[0] != '-')
			temp = betterjoin("-",temp);
		else if (!tempflag->isnegative)
			temp = betterjoin("+",temp);
	}
	return (temp);
}

char *spaceflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *buffer;
	int size;
	char *test;

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
	return (temp);
}

char *mflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
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
	if (tempflag->mflag == -1)
		temp = betterjoin(temp," ");
	return (temp);
}

char *zeroflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	int size;
	char *buffer;
	char *save;

	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	size = tempflag->zero - ft_strlen(temp);
	if (temp[0] == '-')
		save = ft_strsub(temp, 1, ft_strlen(temp) - 1);
	else
		save = ft_strdup(temp);
	if (size > 0)
	{
		buffer = makespace(size, '0');
		save = betterjoin(buffer,save);
	}
	if (temp[0] == '-')
		temp = betterjoin("-",save);
	else
		temp = ft_strdup(save);
	return (temp);
}

char *hashflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	if (ft_strcmp(temp,"0") == 0)
		temp = ft_strdup("0");
	else if(tempflag->conid == 10 && (temp[0] != '0' || temp[1] != 'x'))
		temp = betterjoin("0x",temp);
	else if(tempflag->conid == 11 && (temp[0] != '0' || temp[1] != 'x'))
		temp = betterjoin("0X",temp);
	else if((tempflag->conid == 7 || tempflag->conid == 6) && temp[0] != '0')
		temp = betterjoin("0",temp);
	return (temp);
}

char *extraflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *buffer;
	buffer = "";
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	if (tempflag->extra)
	{
		buffer = makespace(tempflag->extra - ft_strlen(temp), ' ');
		temp = betterjoin(buffer, temp);
	}
	return (temp);
}
char *flagformating(char *str, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *temp = NULL;
	if (tempflag->hash == -1 && (tempflag->zero > 0 || tempflag->mflag > 0))
	{
		if (tempflag->zero > 1)
			tempflag->zero = tempflag->zero - 2;
		else if (tempflag->zero == 1)
			tempflag->zero = 0;
		if (tempflag->mflag > 0)
			tempflag->mflag = tempflag->mflag - 2;
	}
	if ((tempflag->precision > 0 || tempflag->precision == -1))
	temp = percisionflag(str, temp, &tempflag);
	if ((tempflag->mflag == -1) || tempflag->mflag > tempflag->precision)
		temp = mflag(str, temp, &tempflag);
	else if (tempflag->zero && tempflag->precision == 0)
		temp = zeroflag(str, temp, &tempflag);
	if (tempflag->hash == -1 && (tempflag->conid == 6 || tempflag->conid == 7
	|| tempflag->conid == 11 || tempflag->conid == 10))
		temp = hashflag(str, temp, &tempflag);
	if (((tempflag->sign == -1) || (tempflag->sign > 0))
	&& (tempflag->conid > -1))
		temp = signflag(str, temp, &tempflag);
	else if (((tempflag->space == -1) || (tempflag->space > 0))
	&& (ft_strcmp(str,"%") != 0))
		temp = spaceflag(str, temp, &tempflag);
	else if (tempflag->extra > 0)
		temp = extraflag(str, temp, &tempflag);
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	return temp;
}
