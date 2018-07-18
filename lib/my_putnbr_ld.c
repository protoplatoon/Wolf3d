void	my_putnbr_ld(long nb)
{
  long	resultat;
  long	div;
  int	t_base;

  t_base = 10;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  div = 1;
  while ((nb / div) >= t_base)
    div = div * t_base;
  while (div > 0)
    {
      resultat = (nb / div) % t_base;
      div = div / t_base;
      my_putchar(resultat + '0');
    }
}
