int	my_power_rec(int nb, int power)
{
  if (nb <= 0 || power < 0)
    return (0);
  return (power <= 0) ? 1 : nb * my_power_rec(nb, power - 1);
}
