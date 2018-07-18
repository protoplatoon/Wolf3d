int	my_is_prime(int nombre)
{
  int	i;

  i = 2;
  if (nombre <= 1)
    return (0);
  while (i < nombre)
    {
      if (nombre % i == 0)
	return (0);
      i++;
    }
  return (1);
}
