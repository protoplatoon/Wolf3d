#ifndef MLX_ENV_
# define MLX_ENV_
# define ABS(value)	((value) > 0 ? value : (value) * -1)
# define RAD(x)		(x * (M_PI / 180))
# define HEIGHT		(800)
# define WIDTH		(600)
# define ROT_SPEED	(2)
# define WALK_SPEED	(10)
# define CIEL		(0x00C3F4)
# define TERRE		(0x107313)
# define MUR		(0x929B9A)
# define MUR2		(0xBBBBBB)
# define ECHAP		(65307)
# define RIGHT		(65363)
# define LEFT		(65361)
# define UP		(65362)
# define DOWN		(65364)

typedef struct	s_img
{
  void		*img_ptr;
  int		endian;
  int		size_line;
  int		bpp;
  int		width;
  int		height;
  char		*data;
}		t_img;

typedef struct	s_coord
{
  float	x;
  float	y;
}		t_coord;

typedef struct	joueur
{
  t_coord	pos;
  int		alpha;
  int		fov;
  float		d;
  int		p;
}		t_joueur;

typedef struct	s_env
{
  void		*mlx_ptr;
  void		*win_ptr;
  t_img		bg;
  char		**lab;
  int		nb_lin;
  int		nb_col;
  int		bool;
  int		couleur_mur;
  t_joueur	player;
  float		cos[360];
  float		sin[360];
}		t_env;

typedef struct	s_rep
{
  int	x;
  int	y;
  int	z;
}		t_rep;

typedef struct	vecteur
{
  float	x1;
  float	x2;
  float	y1;
  float	y2;
}		t_vect;

void	draw_line(void *mlx_ptr, void *win_ptr, t_vect vect, int couleur);
int	img_put_background(t_img *bg, int x, int y, t_env e);
void	my_pixel_put_to_image(int img_color, t_img *bg, int x, int y);
void	draw_line_to_img(t_img *img, t_vect vect, int couleur);
void	draw_mur(t_env *env);
char	**init_tab(char *filename);
int	gere_key(int keycode, void *param);
int	init_fptr(void (*fptr[6])(t_env *e));
void	move_right(t_env *e);
int	init_sin(float *my_sin);
int	init_cos(float *my_cos);
void	move_left(t_env *e);
void	rot_left(t_env *e);
void	rot_right(t_env *e);
void	my_exit(t_env *e);
void	appli_display(t_env *e);

#endif /* !MLX_ENV_ */
