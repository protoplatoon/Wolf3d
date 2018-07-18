int	my_str_isprintable(char *str)
{
  int	i;

  while (str[i] =! 0)
    {
      if ((str[i] >= 20) && (str[i] <= 126))
	i++;
      else
	return (0);
    }
  return (1);
}
