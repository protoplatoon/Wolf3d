char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      if ((str[i] >= 'A') && (str[i] <= 'Z'))
	str[i] += 32;
      i++;
    }
  my_putchar('\n');
  return (str);
}
