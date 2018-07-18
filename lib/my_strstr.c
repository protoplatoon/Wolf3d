char	*my_strstr(char *str, char *to_find)
{
  int   i;
  int   compteur;

  i = 0;
  compteur  = 0;
  while (str[i] != 0)
    {
      if (str[i] == to_find[compteur])
	  compteur++;
      else
          compteur = 0;
      if (!to_find[compteur])
	  return (to_find);
      i++;
    }
  return (0);
}
