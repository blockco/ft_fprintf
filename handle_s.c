#include "ft_printf.h"

void pf_putstr(void *ptr)
{
	char *str;
	str = (char*)ptr;
	ft_putstr(ptr);
}
