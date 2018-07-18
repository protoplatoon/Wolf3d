char	*my_revstr(char *str)
{
  int	i;
  int	j;
  int	n;
  char	stock;

  i = 0;
  j = my_strlen(str) - 1;
  n = j / 2;
  while (j > n)
    {
      stock = str[i];
      str[i] = str[j];
      str[j] = stock;
      i++;
      j--;
    }
  return (str);
}
