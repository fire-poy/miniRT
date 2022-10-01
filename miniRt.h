/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:33:15 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 17:12:14 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "vector_lib/vector.h"
# include "parser/parser.h"

# define WIN_WIDTH 1800
# define WIN_HEIGHT 900

typedef struct s_equation
{
	t_vect	oc;
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t;
}					t_equation;

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
}					t_camera;					

typedef struct s_light
{
	t_vect	pos;
	float	light;
	t_vect	rgb;
}					t_light;

typedef struct s_cyl
{
	t_vect	pos;
	t_vect	dir;
	t_vect	rgb;
	t_vect	top_center;
	t_vect	bot_center;
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

typedef struct s_window
{
	t_vect	vertical;
	t_vect	horizontal;
	t_vect	corner;
	t_vect	u;
	t_vect	v;
}					t_win;

typedef struct s_obj
{
	int		type;
	int		idx;
	float	dist;
	t_vect	col;
}					t_obj;

typedef struct s_phong
{
	t_vect	ambiant;
	t_vect	diffuse;
	t_vect	specular;
	t_vect	col;
	t_vect	i_s;
	t_vect	l;
	t_vect	r;
	t_vect	v;
	float	k_s;
	float	dotln;
	float	dotrv;
	float	alpha;
}					t_phong;

# ifndef T_Q_OBJ
#  define T_Q_OBJ

typedef struct s_q_obj
{
	int	a;
	int	c;
	int	l;
	int	sp;
	int	pl;
	int	cy;
}	t_q_obj;
# endif

typedef struct s_set
{
	t_sp		*sp_list;
	t_cyl		*cyl_list;
	t_plan		*plan_list;
	t_light		light;
	t_ambiant	ambiant;
	t_camera	cam;
	t_win		win;
	int			current_id;
	t_obj		obj;
	t_vect		normal;
	t_q_obj		q_obj;
}					t_set;	

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

//Parsing
t_q_obj	parsing(char *scene_file, t_set *set);

//Mlx
int		key_hook(int keycode, t_set *set);
int		exit_hook(t_set *set);
void	my_pxl_put(t_mlx *d, int x, int y, int color);

// Render
t_vect	color(t_set *set, t_ray r);
void	render(t_mlx *i, t_set *set);
t_vect	render_core(t_set *set, int x, int y);
t_vect	phong(t_set *set, t_vect p, t_vect o_col);
int		is_in_light(t_set *set, t_vect p);
t_vect	blend_light(t_set *set, t_vect p);
t_vect	reflect(t_vect l_dir, t_vect norm);
void	get_closest_sp(t_set *set, t_ray r);
void	get_closest_pl(t_set *set, t_ray r);
void	get_closest_cyl(t_set *set, t_ray r);
int		get_closest(t_set *set, t_ray r, float t_max);

// Objects
float	hit_sp(t_sp sp, t_ray ray);
float	hit_plan(t_plan pl, t_ray r);
int		hit_cyl(t_set *set, t_cyl cyl, t_ray ray);
int		check_cyl(t_set *set, t_cyl cyl, t_ray ray);
int		check_cap(t_set *set, t_cyl cyl, t_vect pl_pos, t_ray r);
void	fov(t_set *set);

// Utils
t_vect	point_at(t_ray r, float t);
t_vect	col_scaled(t_vect col);
t_vect	ranged(t_vect v);
float	clamp(float x, float min, float max);
void	free_scene(t_set *set);

#endif
