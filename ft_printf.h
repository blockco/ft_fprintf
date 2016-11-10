#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

extern char *g_format;
extern void (*g_gl[14])(va_list *ptr);

typedef	struct s_flags
{
	int hh;
	int h;
	int l;
	int	ll;
	int j;
	int z;
	int hash;
	int	zflag;
	int	mflag;
	int sign;
	int precision;
}				s_flags;
//pf wrappers
void 	pf_putstr(va_list *ptr);
void 	pf_putnbr(va_list *ptr);
void 	pf_putchar(va_list *args);
void 	pf_x_handle(va_list *args);
void 	pf_xlow_handle(va_list *args);
void 	pf_o_handle(va_list *args);
void 	pf_oup_handle(va_list *args);
void 	pf_p_handle(va_list *args);
void	setflags(s_flags **flag);
void	setsymb(s_flags **flag, int *findex, const char *format);
void	findflags(s_flags **flag, int *findex, const char *format);
//extra functions
uintmax_t		ft_pow(uintmax_t nb, int pow);
char	*ft_itoa_base(uintmax_t value, int base);
char	*ft_itoa_baselow(uintmax_t value, int base);
#endif
