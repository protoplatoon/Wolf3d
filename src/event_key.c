#include <math.h>
#include <stdlib.h>

#include "mlx.h"
#include "mlx_env.h"

void	move_left(t_env *e)
{
  float	tmp1;
  float	tmp2;

  tmp1 = e->player.pos.x + WALK_SPEED * e->cos[e->player.alpha - 90] / 100;
  tmp2 = e->player.pos.y + WALK_SPEED * e->sin[e->player.alpha - 90] / 100;
  if ((e->lab[(int)tmp2][(int)tmp1]) == '1')
    return;
  e->player.pos.x = tmp1;
  e->player.pos.y = tmp2;
  appli_display(e);
}

void	rot_left(t_env *e)
{
  if (e->player.alpha - ROT_SPEED < 0)
    (e->player.alpha = 360 + e->player.alpha);
  e->player.alpha -= ROT_SPEED;
  appli_display(e);
}

void	move_right(t_env *e)
{
  float	tmp1;
  float	tmp2;

  tmp1 = e->player.pos.x + WALK_SPEED * e->cos[e->player.alpha + 90] / 100;
  tmp2 = e->player.pos.y + WALK_SPEED * e->sin[e->player.alpha + 90] / 100;
  if ((e->lab[(int)tmp2][(int)tmp1]) == '1')
    return;
  e->player.pos.x = tmp1;
  e->player.pos.y = tmp2;
  appli_display(e);
}

void	rot_right(t_env *e)
{
  if (e->player.alpha + ROT_SPEED >= 360)
    (e->player.alpha = 0);
  e->player.alpha += ROT_SPEED;
  appli_display(e);
}

void	my_exit(t_env *e)
{
  free(e->mlx_ptr);
  free(e->win_ptr);
  free(e->bg.img_ptr);
  exit(1);
}
