int	my_str_isnum(char *str)
{
  int	i;

  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (0);
    }
  return (1);
}
