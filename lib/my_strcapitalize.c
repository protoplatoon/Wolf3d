char	*strcapitalize_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 32;
      i++;
    }
  return (str);
}

char	*my_strcapitalize(char *str)
{
  int	i;
  int	bool;

  i = 0;
  bool = 1;
  strcapitalize_strlowcase(str);
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  if (bool == 1)
	    str[i] = str[i] - 32;
	  bool = 0;
	}
      else if (str[i] >= '0' && str[i] <= '9')
	bool = 0;
      else
	bool = 1;
      i++;
    }
  return (str);
}
