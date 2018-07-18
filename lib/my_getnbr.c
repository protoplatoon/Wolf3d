int	is_neg(int *negatif, char *str)
{
  int	i;

  i = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	*negatif = *negatif - 1;
      else if (str[i] == '+')
	*negatif = *negatif + 1;
      i++;
    }
  return (i);
}

int	pos_base(char c, char *base)
{
  int	pos;
  int	i;

  i = 0;
  pos = 0;
  while (base[pos] != c)
    pos++;
  if (base[pos] != 0)
    return (pos);
  else
    return (-1);
}

int	my_getnbr(char *str)
{
  int	resultat;
  int	len;
  int	negatif;
  int	i;

  negatif = 0;
  resultat = 0;
  len = my_strlen("0123456789");
  i = is_neg(&negatif, str);
  while (str[i] != 0)
    {
      resultat = resultat * len;
      resultat = resultat + pos_base(str[i], "0123456789");
      i++;
    }
  if (negatif < 0)
    return (-resultat);
  else
    return (resultat);
}
