char	*my_strcat(char* dest, char* src)
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
      while (src[i] != '\0')
	{
	  dest[length + i] = src[i];
	  i++;
	}
      dest[length + i] = '\0';
    }
  return (dest);
}
