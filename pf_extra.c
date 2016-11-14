#include "ft_printf.h"

uintmax_t		ft_pow(uintmax_t nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(uintmax_t value, int base)
{
	int		i;
	char	*nbr;
	int		neg;
	uintmax_t zero = 0;

	i = 1;
	neg = 0;
	if (value < zero)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
char	*ft_itoa_baselow(uintmax_t value, int base)
{
	int		i;
	char	*nbr;
	int		neg;
	uintmax_t zero = 0;

	i = 1;
	neg = 0;
	if (value < zero)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

int findsize(int value, int base)
{
	int size;

	size = 0;
	while (value)
	{
		size++;
		value = value / base;
	}
	return size;
}
