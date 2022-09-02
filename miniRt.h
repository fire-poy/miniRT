#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx/mlx.h"
# include "vector_lib/vector.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_plan
{
	t_vect	pos;
	t_vect	dir;
	t_vect	rgb;
}					t_plan;

typedef struct s_ambiant
{
	float	light;
	t_vect	rgb;
}					t_ambiant;

typedef struct s_camera
{
	t_vect	pos;
	t_vect	dir;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_vect	pos;
	float	light;
	t_vect	rgb;
}					t_light;

typedef	struct s_cyl
{
	t_vect	pos;
	t_vect	dir;
	t_vect	rgb;
	float	r;
	float	len;
}					t_cyl;

typedef struct s_ray
{
	float	t;
	t_vect	pos;
	t_vect	dir;
}					t_ray;

typedef struct s_sphere
{
	t_vect	c;
	float	r;
	t_vect	rgb;
}					t_sp;

typedef struct mlx_instance
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}		t_mlx;

typedef struct s_set
{
	t_sp		*sp_list;
	t_cyl		*cyl_list;
	t_plan		*plan_list;
	t_light		light;
	t_ambiant	ambiant;
	t_camera	cam;
}					t_set;

void	my_pxl_put(t_mlx *d, int x, int y, int color);
t_vect	color(t_sp sp, t_ray r);
float	hit_sp(t_sp sp, t_ray ray);
t_vect	point_at(t_ray r, float t);
int		key_hook(int keycode);

#endif
