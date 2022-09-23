/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:29:20 by slott             #+#    #+#             */
/*   Updated: 2022/09/23 17:16:55 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

t_vect	color(t_set *set, t_ray r)
{
	t_vect	col;
	t_vect	v1;

	if (get_closest(set, r, 1e+42) != -1)
	{
		v1 = point_at(r, set->obj.dist);
		col = blend_light(set, v1);
		return (col);
	}
	col = init_vec(0, 0, 0);
	return (col);
}

void	render(t_mlx *i, t_set *set)
{
	t_ray	ray;
	float	u;
	float	v;
	int		x;
	int		y;

	x = 0;
	while (x < 1800)
	{
		y = 0;
		while (y < 900)
		{
			u = (float)x / (float)1800;
			v = (float)y / (float)900;
			ray.pos = set->cam.pos;
			ray.dir = plus(3, set->win.corner, \
				fois_x(set->win.horizontal, u), fois_x(set->win.vertical, v));
			ray.dir = moins(2, ray.dir, set->cam.pos);
			my_pxl_put(i, x, y, to_color(color(set, ray)));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(i->mlx_ptr, i->win_ptr, i->img, 0, 0);
}
