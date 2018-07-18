int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (i < my_strlen(s1))
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}
