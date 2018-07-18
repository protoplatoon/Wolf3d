int	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
