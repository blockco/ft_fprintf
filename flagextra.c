#include "ft_printf.h"

int findprecisionextra(const char *format, int *findex)
{
	int i = 0;
	int temp;
	temp = *findex;
	while(format[temp] >= '0' && format[temp] <= '9')
	{
		if (format[temp + 1] >= '0' && format[temp + 1] <= '9')
		{
			i = i + format[temp] - 48;
			i = i * 10;
		}
		else
			i = i + format[temp] - 48;
		temp++;
	}
	*findex = temp;
	if (i == 0)
		i = -1;
	return i;
}

void	setsymb(s_flags **flag, int *findex, const char *format)
{
	int temp;
	s_flags *tempflag;
	tempflag = *flag;
	temp = *findex;
		if (format[temp] == '#')
			tempflag->hash = findhash(format, &temp);
		else if (format[temp] == '0')
			tempflag->zero = findprecision(format, &temp);
		else if (format[temp] == '-')
			tempflag->mflag = findprecision(format, &temp);
		else if (format[temp] == '+')
			tempflag->sign = findprecisionspace(format, &temp);
		else if (format[temp] == ' ')
			tempflag->space = findprecisionspace(format, &temp);
		else if (format[temp + 1] >= '0' && format[temp + 1] <= '9')
			tempflag->extra = findprecisionspace(format, &temp);
	*findex = temp;
	*flag = tempflag;
}

void	findflags(s_flags **flag, int *findex, const char *format) //move
{
	int temp;
	s_flags *tempflag;
	tempflag = *flag;
	temp = *findex;
	if ((format[temp] == 'l' && format[temp + 1] == 'l') ||
			(format[temp] == 'h' && format[temp + 1] == 'h'))
	{
		if (format[temp] == 'l' && format[temp + 1] == 'l')
			tempflag->ll = 1;
		else if (format[temp] == 'h' && format[temp + 1] == 'h')
			tempflag->hh = 1;
		temp = temp + 2;
	}
	else if (format[temp] == 'h' || format[temp] == 'l' ||
			format[temp] == 'j' || format[temp] == 'z')
	{
		if (format[temp] == 'h')
			tempflag->h = 1;
		else if (format[temp] == 'l')
			tempflag->l = 1;
		else if (format[temp] == 'j')
			tempflag->j = 1;
		else if (format[temp] == 'z')
			tempflag->zflag = 1;
		temp++;
	}
	*findex = temp;
	*flag = tempflag;
}
