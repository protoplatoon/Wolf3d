#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "mlx_env.h"

char	**init_tab(char *filename)
{
  int	fd;
  char	*line;
  char	**tab;
  int	i;

  i = -1;
  if ((fd = open(filename, O_RDONLY)) == -1)
    return (0);
  if ((tab = malloc(sizeof(char *) * BUF_SIZE)) == 0)
    return (0);
  while ((line = get_next_line(fd)))
    tab[++i] = line;
  return (tab);
}

int	init_cos(float my_cos[])
{
  int	i;

  i = -1;
  while (++i < 360)
    my_cos[i] = cos(RAD(i));
  return (1);
}

int	init_sin(float my_sin[])
{
  int	i;

  i = -1;
  while (++i < 360)
    my_sin[i] = sin(RAD(i));
  return (1);
}
