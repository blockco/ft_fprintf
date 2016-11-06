#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

extern char *g_format;
extern void (*g_gl[14])(va_list *ptr);
//pf wrappers
void 	pf_putstr(va_list *ptr);
void 	pf_putnbr(va_list *ptr);
void 	pf_putchar(va_list *args);
void 	pf_x_handle(va_list *args);
void 	pf_xlow_handle(va_list *args);
void 	pf_o_handle(va_list *args);
//extra functions
int		ft_pow(int nb, int pow);
char	*ft_itoa_base(int value, int base);
char	*ft_itoa_baselow(int value, int base);
#endif
