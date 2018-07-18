#include <math.h>

#include "mlx.h"
#include "mlx_env.h"

void	 appli_display(t_env *e)
{
  img_put_background(&e->bg, HEIGHT, WIDTH, *e);
  draw_mur(e);
  mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->bg.img_ptr, 0, 0);
}

void	move_down(t_env *e)
{
  float	tmp1;
  float	tmp2;

  tmp1 = e->player.pos.x - WALK_SPEED * e->cos[e->player.alpha] / 100;
  tmp2 = e->player.pos.y - WALK_SPEED * e->sin[e->player.alpha] / 100;
  if (e->lab[(int)tmp2][(int)tmp1] == '1')
    return;
  else
    {
      e->player.pos.x = tmp1;
      e->player.pos.y = tmp2;
      appli_display(e);
    }
}

void	move_up(t_env *e)
{
  float	tmp1;
  float	tmp2;

  tmp1 = e->player.pos.x + WALK_SPEED * e->cos[e->player.alpha] / 100;
  tmp2 = e->player.pos.y + WALK_SPEED * e->sin[e->player.alpha] / 100;
  if ((e->lab[(int)tmp2][(int)tmp1]) == '1')
    return;
  e->player.pos.x = tmp1;
  e->player.pos.y = tmp2;
  appli_display(e);
}

int	init_fptr(void (*fptr[6])(t_env *e))
{
  fptr[0] = my_exit;
  fptr[1] = rot_right;
  fptr[2] = rot_left;
  fptr[3] = move_up;
  fptr[4] = move_down;
  fptr[5] = move_left;
  fptr[6] = move_right;
  return (1);
}
