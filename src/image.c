#include <math.h>

#include "mlx.h"
#include "mlx_env.h"

void	my_pixel_put_to_image(int img_color, t_img *bg, int x, int y)
{
  bg->data[(x * (bg->bpp / 8)) + (y * bg->size_line)] = (img_color);
  bg->data[(x * (bg->bpp / 8)) + (y * bg->size_line) + 1] = (img_color) >> 8;
  bg->data[(x * (bg->bpp / 8)) + (y * bg->size_line) + 2] = (img_color) >> 16;
}

void	draw_line_to_img(t_img *img, t_vect vect, int couleur)
{
  int	x;
  int	y;
  int	i;
  int	sx;
  int	sy;
  float	l;

  if (vect.x1 != vect.x2)
    sx = (vect.x2 - vect.x1) / ABS(vect.x2 - vect.x1);
  else
    sx = 1;
  if (vect.y1 != vect.y2)
    sy = (vect.y2 - vect.y1) / ABS(vect.y2 - vect.y1);
  else
    sy = 1;
  l = sqrt(ABS(vect.x2 - vect.x1) * ABS(vect.x2 - vect.x1)
	   + ABS(vect.y2 - vect.y1) * ABS(vect.y2 - vect.y1));
  i = -1;
  while (++i < l)
    {
      x = vect.x1 + sx * i * ((float)ABS(vect.x2 - vect.x1) / l);
      y = vect.y1 + sy * i * ((float)ABS(vect.y2 - vect.y1) / l);
      my_pixel_put_to_image(couleur, img, x, y);
    }
}

int	img_put_background(t_img *bg, int x, int y, t_env e)
{
  int	i;
  int	j;

  i = 0;
  if (!bg->data)
    return (0);
  while (i++ < x)
    {
      j = 0;
      while (j++ < y)
	{
	  if (j < y / 2)
	    my_pixel_put_to_image(CIEL, bg, i, j);
	  else
	    my_pixel_put_to_image(TERRE, bg, i, j);
	}
    }
  return (1);
}
