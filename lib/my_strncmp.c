int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}
