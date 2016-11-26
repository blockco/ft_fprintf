#include "ft_printf.h"

uintmax_t		ft_pow(uintmax_t nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char *ft_itoa_baselow(ssize_t value, intmax_t base)
{
	char hex[16] = "0123456789abcdef";
	intmax_t n = value;
	intmax_t size;
	char *ret;
	if (value == 0)
		return ("0");
	if (value < 0)
		n = -1 * n;
	size = findsize(n, base);
	if (value < 0 && base == 10)
		size++;
	ret = (char*)malloc(size + 1);
	ret[size] = '\0';
	size--;
	while (n)
	{
		ret[size] = hex[n % base];
		n = n / base;
		size--;
	}
	if (value < 0 && base == 10)
		ret[0] = '-';
	return ret;
}

char *ft_itoa_base(ssize_t value, int base)
{
	char hex[16] = "0123456789ABCDEF";
	intmax_t n = value;
	intmax_t size;
	char *ret;
	if (value == 0)
		return ("0");
	if (value < 0)
		n = -1 * n;
	size = findsize(n, base);
	if (value < 0 && base == 10)
		size++;
	ret = (char*)malloc(size + 1);
	ret[size] = '\0';
	size--;
	while (n)
	{
		ret[size] = hex[n % base];
		n = n / base;
		size--;;
	}
	if (value < 0 && base == 10)
		ret[0] = '-';
	return ret;
}

char *ft_itoa_baselowu(uintmax_t value, uintmax_t base)
{
	char hex[16] = "0123456789abcdef";
	uintmax_t n = value;
	uintmax_t size;
	char *ret;
	if (value == 0)
		return ("0");
	size = findsize(n, base);
	ret = (char*)malloc(size + 1);
	ret[size] = '\0';
	size--;
	while (n)
	{
		ret[size] = hex[n % base];
		n = n / base;
		size--;;
	}
	return ret;
}

char *ft_itoa_baseu(uintmax_t value, uintmax_t base)
{
	char hex[16] = "0123456789ABCDEF";
	uintmax_t n = value;
	uintmax_t size;
	char *ret;
	if (value == 0)
		return ("0");
	size = findsize(n, base);
	ret = (char*)malloc(size + 1);
	ret[size] = '\0';
	size--;
	while (n)
	{
		ret[size] = hex[n % base];
		n = n / base;
		size--;;
	}
	return ret;
}

int findsize(uintmax_t value, int base)
{
	uintmax_t size;

	size = 0;
	while (value)
	{
		size++;
		value = value / base;
	}
	return size;
}
