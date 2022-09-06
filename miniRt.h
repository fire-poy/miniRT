/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:33:15 by slott             #+#    #+#             */
/*   Updated: 2022/09/06 13:04:50 by mpons            ###   ########.fr       */
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

#define WIN_WIDTH 1800
#define WIN_HEIGHT 900

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

typedef struct s_window
{
	t_vect	vertical;
	t_vect	horizontal;
	t_vect	corner;
	t_vect	u;
	t_vect	v;
}					t_win;

typedef struct s_set
{
	t_sp		*sp_list;
	t_cyl		*cyl_list;
	t_plan		*plan_list;
	t_light		light;
	t_ambiant	ambiant;
	t_camera	cam;
	t_win		win;
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

void	parsing(char *scene_file, t_set *set);
void	my_pxl_put(t_mlx *d, int x, int y, int color);
t_vect	color(t_sp sp, t_ray r);
float	hit_sp(t_sp sp, t_ray ray);
t_vect	point_at(t_ray r, float t);
void	init_set(t_set *set);
void	render(t_mlx *i, t_set *set);
void	fov(t_set *set);
int		key_hook(int keycode);
int		exit_hook(void);
//void	*ft_calloc(size_t count, size_t size);
//void	ft_bzero(void *s, size_t n);

#endif
