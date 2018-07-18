int	my_find_prime_sup(int nb)
{
  int	suiv;
  int	nbr;

  nbr = nb + 1;
  suiv = my_is_prime(nbr);
  while (suiv == 0)
    {
      nbr++;
      suiv = my_is_prime(nbr);
    }
  return (nbr);
}
