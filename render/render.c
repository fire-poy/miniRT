/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:29:20 by slott             #+#    #+#             */
/*   Updated: 2022/09/06 16:26:27 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../miniRt.h"

t_vect	color(t_set *set, t_ray r)
{
	t_vect	col;
	t_vect	u_dir;
	t_vect	v1;
	t_vect	v2;
	float	t;
	int		i;

	i = 0;
	v1 = init_vec(1, 1, 1);
	v2 = init_vec(0.5, 0.7, 1);
	while (set->sp_list[i].r)
	{
		t = hit_sp(set->sp_list[i], r);
		if (t > 0.0)
		{
			u_dir = unit_vector(moins(2, point_at(r, t), set->sp_list[i].c));
			return (fois_x(plus_x(u_dir, 1), 0.5));
		}
		i++;
	}
	u_dir = unit_vector(r.dir);
	t = 0.5 * (u_dir.y + 1);
	col = plus(2, fois_x(v1, 1 - t), fois_x(v2, t));
	return (col);
}

void	render(t_mlx *i, t_set *set)
{
	t_ray	ray;
	t_vect	col;
	float	u;
	float	v;

	for (int y = 899; y >= 0; y--)
	{
		for (int x = 0; x < 1800; x++)
		{
			u = (float)x / (float)1800;
			v = (float)y / (float)900;
			ray.pos = set->cam.pos;
			ray.dir = plus(3, set->win.corner, \
					fois_x(set->win.horizontal, u), fois_x(set->win.vertical, v));
			col = color(set, ray);
			my_pxl_put(i, x, y, to_color(col));
		}
	}
	mlx_put_image_to_window(i->mlx_ptr, i->win_ptr, i->img, 0, 0);
}
