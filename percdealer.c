#include "ft_printf.h"

char	*percdealer(t_flags **flag)
{
	t_flags	*tempflag;
	char	*ret;
	char	c;

	tempflag = *flag;
	ret = ft_strdup("%");
	if ((tempflag->zero == -1 || tempflag->zero > 0) && tempflag->mflag == 0)
		c = '0';
	else
		c = ' ';
	if (tempflag->mflag > 0)
		return (betterjoin(ret, makespace(tempflag->mflag - 1, c)));
	if (tempflag->zero > 0)
		return (betterjoin(makespace(tempflag->zero - 1, c), ret));
	if (tempflag->space > 0)
		return (betterjoin(makespace(tempflag->space - 1, c), ret));
	if (tempflag->extra > 0)
		return (betterjoin(makespace(tempflag->extra - 1, c), ret));
	return ("%");
}
