#include <stdarg.h>
#include <stdio.h>

int	put_nbrbase_(va_list *list, const char *str)
{
  int	c;

  c = va_arg(list, int);
  my_putnbr_base(c, "0123456789abcdef");
  return (0);
}

int	put_nbroctal(va_list *list, const char *str)
{
  int	c;

  c = va_arg(list, int);
  my_putnbr_base(c, "01234567");
  return (0);
}

int	putnbr_u(va_list *list, const char *str)
{
  int	c;

  c = va_arg(list, int);
  my_putnbr_base(c, "0123456789");
  return (0);
}

int	put_char(va_list *list, const char *str)
{
  int	c;

  c = va_arg(list, int);
  my_putchar(c);
  return (0);
}

int	putptr(va_list *list, const char *str)
{
  long	c;

  c = va_arg(list, long);
  my_putstr("0x");
  my_putnbr_base_ld(c, "0123456789abcdef");
  return (0);
}
