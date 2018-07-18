#include <stdlib.h>

int	find_word(char *s)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 0;
  while (s[i])
    {
      if ((s[i] >= 'a' && s[i] <= 'z')
	  || (s[i] >= 'A' && s[i] <= 'Z')
          || (s[i] >= '0' && s[i] <= '9'))
        {
          cpt = cpt + 1;
          while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
                          || (s[i] >= 'A' && s[i] <= 'Z')
                          || (s[i] >= '0' && s[i] <= '9')))
            i = i + 1;
        }
      i = i + 1;
    }
  return (cpt);
}

int	is_print(char *str, int *a)
{
  int	i;

  i = *a;
  while ((str[i] <= '/' && str[i] >= 32)
	 || (str[i] <= '@' && str[i] >= ':' )
	 || (str[i] <= '`' && str[i] >= '[')
	 || (str[i] <= 127 && str[i] >= '{'))
    i++;
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;
  int	nb;

  i = 0;
  k = 0;
  nb = find_word(str);
  if ((tab = malloc(sizeof(char *) * nb + 1)) != 0)
    retrun (0);
  while (str[i] != '\0')
    {
      i = is_print(str, &i);
      if ((tab[k] = malloc(sizeof(char) * (i + 1))) != 0)
	return (0);
      j = 0;
      while ((str[i] >= 48 && str[i] <= 57)
	     || (str[i] >= 65 && str[i] <= 90)
	     || (str[i] >= 97 && str[i] <= 122))
	tab[k][j++] = str[i++];
      k++;
    }
  tab[k] = NULL;
  return (tab);
}
