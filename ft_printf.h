/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:29:27 by rpassafa          #+#    #+#             */
/*   Updated: 2016/12/15 23:21:11 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef	struct s_flags
{
	// biggest to smallest
	int j;
	int	ll;
	int l;
	int h;
	int hh;
	int hash;
	int	zflag;
	int	mflag;
	int sign;
	int space;
	int precision;
	int isnegative;
	int zero;
	int conid;
	int size;
	int extra;
	char *ret;
}				s_flags;

extern char *g_format;
extern void (*g_gl[14])(va_list *ptr, s_flags **flag);
//pf wrappers
void 	pf_putstr(va_list *ptr, s_flags **flag);
void 	pf_putnbr(va_list *args, s_flags **flag);
void 	pf_putchar(va_list *args, s_flags **flag);
void 	pf_x_handle(va_list *args, s_flags **flag);
void 	pf_xlow_handle(va_list *args, s_flags **flag);
void 	pf_o_handle(va_list *args, s_flags **flag);
void 	pf_oup_handle(va_list *args, s_flags **flag);
void 	pf_p_handle(va_list *args, s_flags **flag);
void	pf_u_handle(va_list *args, s_flags **flag);
void pf_uup_handle(va_list *args, s_flags **flag);
void pf_dup_handle(va_list *args, s_flags **flag);
//extra functions
int findsize(uintmax_t value, int base);
char *betterjoin(char *first, char *second);
char *charadder(char *str, char c);
char *ft_itoa_baseint(intmax_t value, int base);
//handle
uintmax_t		ft_pow(uintmax_t nb, int pow);
char *ft_itoa_base(ssize_t value, int base);
char *ft_itoa_baselow(ssize_t value, intmax_t base);
char *ft_itoa_baseuint(uintmax_t value, int base);
char *ft_itoa_baselowuint(uintmax_t value, int base);
char *ft_itoa_baselowu(uintmax_t value, uintmax_t base);
char *ft_itoa_baseu(uintmax_t value, uintmax_t base);
//flag handlers
void	setflags(s_flags **flag);
void	setsymb(s_flags **flag, int *findex, const char *format);
void	findflags(s_flags **flag, int *findex, const char *format);
int 	checkzeroflag(s_flags **flag);
int 	findprecision(const char *format, int *findex);
int 	findprecisionspace(const char *format, int *findex);
int 	findprecisionextra(const char *format, int *findex);
int 	checkoptions(s_flags **flag);
char 	*flagformatingstrings(char *str, s_flags **flag);
//handle options
int 	findprecision(const char *format, int *findex);
char 	*flagformating(char *str, s_flags **flag);
void 	isnegative(s_flags **flag, intmax_t data);
char	*makespace(int size, int c);
char*	percisionflag(char *str, char *temp, s_flags **flag);
char 	*signflag(char *str, char *temp, s_flags **flag);
char	*spaceflag(char *str, char *temp, s_flags **flag);
char	*zeroflag(char *str, char *temp, s_flags **flag);
char 	*hashflag(char *str, char *temp, s_flags **flag);
char 	*extraflag(char *str, char *temp, s_flags **flag);
char	*mflag(char *str, char *temp, s_flags **flag);
//handle Strings
char* percdealer(s_flags **flag);
//printf
int ft_printf(const char *format, ...);
#endif
