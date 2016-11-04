#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

extern char *g_format;
extern void (*g_gl[14])(va_list *ptr);

void pf_putstr(va_list *ptr);
void pf_putnbr(va_list *ptr);
void pf_putchar(va_list *args);
void pf_x_handle(va_list *args);
void pf_o_handle(va_list *args);
char	*ft_itoa_base(int value, int base);
int		ft_pow(int nb, int pow);
#endif
