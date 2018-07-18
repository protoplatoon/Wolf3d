#include <stdarg.h>

int	put_str(va_list *list, const char *str)
{
  char	*c;

  c = va_arg(list, char *);
  my_putstr(c);
  return (0);
}

int	put_nbr(va_list *list, const char *str)
{
  int	c;

  c = va_arg(list, int);
  my_putnbr(c);
  return (0);
}

int	put_str_(va_list *list, const char *str)
{
  char	*c;

  c = va_arg(list, char *);
  my_showstr(c);
  return (0);
}

int	put_nbrbase(va_list *list, const char *str)
{
  int	c;

  c = va_arg(list, int);
  my_putnbr_base(c, "0123456789ABCDEF");
  return (0);
}

int	put_err(va_list *list, const char *str)
{
  my_putchar('%');
  return (0);
}
