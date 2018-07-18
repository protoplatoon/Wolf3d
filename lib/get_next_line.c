#include <stdlib.h>

#include "my.h"

void	init(char buf[], int size)
{
  int	i;

  i = -1;
  while (++i < size)
    buf[i] = 0;
}

char	*my_realloc(char *str, int size)
{
  int	i;
  char	*new;

  i = -1;
  while (str[++i]);
  new = 0;
  if ((new = (char *)malloc(sizeof(char *) * (i + size))) == 0)
    return (0);
  i = -1;
  while (str[++i] != 0)
    new[i] = str[i];
  free(str);
  str = 0;
  return (new);
}

int	get_read(int fd, char buf[], int size, int *i)
{
  int	nbr;

  *i = 0;
  init(buf, size);
  if ((nbr = read(fd, buf, size)) == 0)
    return (0);
  else
    return (nbr);
}

char		*get_next_line(const int fd)
{
  static char	buf[BUF_SIZE];
  static int	i = 0;
  static int	nb_r;
  char		*str;
  int		sizeline;
  int		bool;

  bool = 0;
  sizeline = 0;
  if ((str = malloc(sizeof(char) * BUF_SIZE)) == 0)
    return (0);
  while (bool != 1)
    {
      if (i == 0 || (i == BUF_SIZE && nb_r != 0))
	{
	  nb_r = get_read(fd, buf, BUF_SIZE, &i);
	  str = my_realloc(str, nb_r);
	}
      if (buf[i] == 0 || nb_r == 0)
	return (0);
      (buf[i] == '\n') ? (bool = 1): (str[sizeline++] = buf[i++]);
    }
  str[sizeline] = 0;
  i++;
  return (str);
}
