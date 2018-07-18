char	*my_strncat(char *dest, char *src, int n)
{
  int	length;
  int	i;

  i = 0;
  length = my_strlen(dest);
  if (dest == 0)
    return (dest);
  else if (src == 0)
    return (dest);
  else
    {
      while (i < n && src[i] != '\0')
	{
	  dest[length + i] = src[i];
	  i++;
	}
      dest[length + i] = '\0';
    }
  return (dest);
}
