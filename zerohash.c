#include "ft_printf.h"

char *zeroflagextra(s_flags *tempflag, int size, char *buffer, char *save)
{
	if (tempflag->precision == 0)
		buffer = makespace(size, '0');
	else if (tempflag->precision > 0)
		buffer = makespace(size, ' ');
	return(betterjoin(buffer,save));
}

char *zeroflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	int size;
	char *buffer;
	char *save;
	buffer = "";

	if (tempflag->sign == -1 || tempflag->space == -1)
		tempflag->zero--;
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	size = tempflag->zero - ft_strlen(temp);
	if (temp[0] == '-')
		save = ft_strsub(temp, 1, ft_strlen(temp) - 1);
	else
		save = ft_strdup(temp);
	if (size > 0)
	{
		save = zeroflagextra(tempflag, size, buffer, save);
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
