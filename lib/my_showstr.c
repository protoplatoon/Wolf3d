int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < ' ' || str[i] > '~')
        {
          my_putchar('\\');
          if (str[i] < 14)
	    my_putchar('0');
          my_putnbr_base(str[i], "01234567");
        }
      else
	my_putchar(str[i]);
      i++;
    }
  return (0);
}
