#include <mlx.h>
#include <stdlib.h>
#include <X.h>

#include "mlx_env.h"

int	gere_key(int keycode, void *param)
{
  t_env	*e;
  void	(*fptr[7])(t_env *e);
  int	tab[7] = {ECHAP, RIGHT, LEFT, UP, DOWN, 'a', 'e'};
  int	i;

  i = -1;
  e = param;
  while (tab[++i] && tab[i] != keycode);
  if (!init_fptr(fptr))
    return (0);
  if (i > 4)
    return (0);
  fptr[i](e);
  return (0);
}

int	gere_expose(t_env *params)
{
  mlx_put_image_to_window(params->mlx_ptr, params->win_ptr,
			  params->bg.img_ptr, 0, 0);
  return (0);
}

int	init_env(t_env *env)
{
  env->player.pos.x = 1;
  env->player.pos.y = 1;
  env->player.alpha = 45;
  env->player.d = 0.5;
  env->couleur_mur = MUR;
  env->bool = 0;
  init_cos(env->cos);
  init_sin(env->sin);
  if (!(env->mlx_ptr = mlx_init()))
    return (0);
  if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, HEIGHT, WIDTH, "Wolf 3D")))
    return (0);
  if (!(env->bg.img_ptr = mlx_new_image(env->mlx_ptr, HEIGHT, WIDTH)))
    return (0);
  if (!(env->bg.data = mlx_get_data_addr(env->bg.img_ptr, &env->bg.bpp,
					&env->bg.size_line, &env->bg.endian)))
    return (0);
  img_put_background(&env->bg, HEIGHT, WIDTH, *env);
  if (!(mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->bg.img_ptr,
				0, 0)))
    return (0);
  return (1);
}

void	my_free(t_env *e)
{
  free(e->mlx_ptr);
  free(e->win_ptr);
  free(e->bg.img_ptr);
}

int	main(int ac, char **av)
{
  t_env	env;
  int	i;

  i = -1;
  if (ac > 1)
    {
      if (!(env.lab = init_tab(av[1])))
	return (0);
      if (init_env(&env) == 0)
	return (0);
      draw_mur(&env);
    }
  else
    return (0);
  mlx_hook(env.win_ptr, KeyPress, KeyRelease,  gere_key, &env);
  mlx_expose_hook(env.win_ptr, gere_expose, &env);
  mlx_loop(env.mlx_ptr);
  my_free(&env);
  return (1);
}
