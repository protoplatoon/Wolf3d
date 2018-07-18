#include <stdarg.h>
#include <stdlib.h>

#include "printf.h"

int		find(char str)
{
  char		opt[14];
  int		cpt;

  cpt = 0;
  opt[0] = 's';
  opt[1] = 'd';
  opt[2] = 'x';
  opt[3] = 'X';
  opt[4] = 'c';
  opt[5] = 'u';
  opt[6] = 'o';
  opt[7] = 'S';
  opt[8] = 'p';
  opt[9] = 'b';
  opt[10] = 'l';
  while (cpt < 11)
    {
      if (opt[cpt] == str)
	return (cpt);
      cpt++;
    }
  return (11);
}

int	put_b(va_list *list, const char *str)
{
  int	c;

  c = va_arg(list, int);
  my_putnbr_base(c, "01");
  return (0);
}

int	put_ld(va_list *list, const char *str)
{
  long int	c;

  c = va_arg(list, long int);
  my_putnbr_ld(c);
  return (0);
}

int	init_ptr(int (*fptr[])(va_list *, const char *))
{
  fptr[0] = &put_str;
  fptr[1] = &put_nbr;
  fptr[2] = &put_nbrbase_;
  fptr[3] = &put_nbrbase;
  fptr[4] = &put_char;
  fptr[5] = &putnbr_u;
  fptr[6] = &put_nbroctal;
  fptr[7] = &put_str_;
  fptr[8] = &putptr;
  fptr[9] = &put_b;
  fptr[10] = &put_ld;
  fptr[11] = &put_err;
  return (0);
}

int		my_printf(const char *format, ...)
{
  va_list	list;
  int		a;
  int		(*fptr[14])(va_list *, const char *);

  init_ptr(fptr);
  va_start(list, format);
  a = -1;
  while (format[++a] != '\0')
    {
      if (format[a] == '%')
	{
	  if (find(format[a + 1]) != 11)
	    {
	      fptr[find(format[++a])](&list, format);
	      if (find(format[a]) == 10)
		a = a + 1;
	    }
	  else
	    my_putchar(format[a]);
	}
      else
	my_putchar(format[a]);
    }
  va_end(list);
  return (0);
}
