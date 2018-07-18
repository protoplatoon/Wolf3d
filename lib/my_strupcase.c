char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      if ((str[i] >= 'a') && (str[i] <= 'z'))
	  str[i] -= 32;
      i++;
    }
  my_putchar('\n');
  return (str);
}
