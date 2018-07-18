void		my_putnbr_base_ld(long int nb, char *base)
{
  long int	resultat;
  long int	div;
  int		t_base;

  t_base = my_strlen(base);
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
      my_putchar(base[resultat]);
    }
}
