/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:33:15 by slott             #+#    #+#             */
/*   Updated: 2022/08/31 17:48:53 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx/mlx.h"
# include "vector_lib/vector.h"
# include <stdlib.h>

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

void	my_pxl_put(t_mlx *d, int x, int y, int color);
t_vect	color(t_sp sp, t_ray r);
float	hit_sp(t_sp sp, t_ray ray);
t_vect	point_at(t_ray r, float t);
int		key_hook(int keycode);

#endif
