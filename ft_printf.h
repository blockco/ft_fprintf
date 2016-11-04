#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

char *g_format = "sSpdDioOuUxXcC";

void pf_putstr(va_list *ptr);
void pf_putnbr(va_list *ptr);
void pf_putchar(va_list *args);
void pf_x_handle(va_list *args);
void (*g_gl[14])(va_list *ptr) =
{
	&pf_putstr, 	//0			s
	&pf_putstr, 	//1 		S
	NULL,			//2 		p
	&pf_putnbr, 	//3			d
	NULL, 			//4			D
	&pf_putnbr, 	//5			i
	NULL, 			//6			o
	NULL, 			//7			O
	NULL, 			//8			u
	NULL, 			//9			U
	&pf_x_handle, 	//10		x
	NULL, 			//11		X
	&pf_putchar, 	//12		c
	&pf_putchar, 	//13		C
};
				//012345678
				#endif
