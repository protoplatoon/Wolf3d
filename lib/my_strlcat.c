char	*my_strlcat(char *dest, char *src, int size)
{
  int	j;
  int	i;

  i = 0;
  j = 0;
  while (dest[i])
    i++;
  while (src[j] && i < size)
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
  return dest;
}
