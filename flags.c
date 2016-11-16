#include "ft_printf.h"

void	setflags(s_flags **flag) //move
{
	s_flags *tempflag;
	tempflag = *flag;
	tempflag->hh = 0;
	tempflag->h = 0;
	tempflag->l = 0;
	tempflag->ll = 0;
	tempflag->j = 0;
	tempflag->z = 0;
	tempflag->hash = 0;
	tempflag->zflag = 0;
	tempflag->mflag = 0;
	tempflag->sign = 0;
	tempflag->space = 0;
}

int findprecision(const char *format, int *findex)
{
	int i = 0;
	int temp;

	temp = *findex;
	temp++;
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
	return i;
}

int findprecisionspace(const char *format, int *findex)
{
	int i = 0;
	int temp;

	temp = *findex;
	temp++;
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
	return i;
}

void	setsymb(s_flags **flag, int *findex, const char *format)
{
	int temp;
	s_flags *tempflag;
	tempflag = *flag;
	temp = *findex;
	while (format[temp] == '#' || format[temp] == '0'
		|| format[temp] == '-' || format[temp] == '+'
		|| format[temp] == ' ')
	{
		if (format[temp] == '#')
		{
			tempflag->hash = 1;
			temp++;
		}
		else if (format[temp] == '0')
			tempflag->zflag = findprecision(format, &temp);
		else if (format[temp] == '-')
			tempflag->mflag = findprecision(format, &temp);
		else if (format[temp] == '+')
		{
			tempflag->sign = 1;
			temp++;
		}
		else if (format[temp] == ' ')
				tempflag->space = findprecisionspace(format, &temp);
	}
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
			tempflag->z = 1;
		temp++;
	}
	*findex = temp;
	*flag = tempflag;
}
