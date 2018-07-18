int	my_str_islower(char *str)
{
  int	i;

  while (str[i] =! 0)
    {
      if ((str[i] >= 'a') && (str[i] <= 'z'))
	i++;
      else
	return (0);
    }
  return (1);
}
