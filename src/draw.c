#include <math.h>

#include "mlx.h"
#include "mlx_env.h"

void	check_color(t_env *env, float i, float j, int *bool)
{
  if ((int)round(i * 100) % 100 == 0 && (int)round(j * 100) % 100 != 0)
    {
      *bool = 0;
      env->couleur_mur = MUR;
    }
  else if ((int)round(i * 100) % 100 != 0 && (int)round(j * 100) % 100 == 0)
    {
      *bool = 1;
      env->couleur_mur = MUR2;
    }
  else
    {
      if (*bool == 0)
	env->couleur_mur = MUR;
      else if (*bool == 1)
	env->couleur_mur = MUR2;
    }
}

float		calc(t_env *env, t_vect *vect, float x)
{
  float		i;
  float		j;
  float		k;
  int		bool;

  bool = 0;
  k = 0;
  vect->x1 = env->player.d;
  vect->y1 = (((HEIGHT / 2) - x) / HEIGHT);
  vect->x2 = (vect->x1 * env->cos[env->player.alpha]
	      - vect->y1 * -env->sin[env->player.alpha]);
  vect->y2 = (vect->x1 * env->sin[env->player.alpha]
	       + vect->y1 * -env->cos[env->player.alpha]);
  while (bool != 1 && k < 10000)
    {
      i = env->player.pos.x + k * vect->x2;
      j = env->player.pos.y + k * vect->y2;
      if (env->lab[(int)j][(int)i] == '1')
	bool = 1;
      k = k + 0.006;
    }
  check_color(env, i, j, &env->bool);
  if (k < 1)
    k = 1;
  return (k);
}

void		draw_mur(t_env *env)
{
  float		wallsize;
  t_vect	vect;
  float		x;

  x = 0;
  while (x++ < HEIGHT)
    {
      wallsize = (WIDTH / (2 * calc(env, &vect, x)));
      vect.x1 = x;
      vect.y1 = WIDTH / 2 + wallsize;
      vect.x2 = x;
      vect.y2 = WIDTH / 2 - wallsize;
      draw_line_to_img(&(env->bg), vect, env->couleur_mur);
    }
}
