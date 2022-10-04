/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:29:20 by slott             #+#    #+#             */
/*   Updated: 2022/10/03 14:05:37 by mpons            ###   ########.fr       */
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
	t_vect	col;
	int		x;
	int		y;

	x = 0;
	while (x < 1800)
	{
		y = 0;
		while (y < 900)
		{
			col = render_core(set, x, y);
			my_pxl_put(i, x, y, to_color(col));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(i->mlx_ptr, i->win_ptr, i->img, 0, 0);
}

t_vect	render_core(t_set *set, int x, int y)
{
	t_ray	r;
	t_vect	col;
	float	u;
	float	v;
	float	s;

	s = 0.0;
	col = init_vec(0, 0, 0);
	while (s <= 0.9)
	{
		u = (float)(x + s) / (float)1800;
		v = (float)(y + s) / (float)900;
		r.pos = set->cam.pos;
		r.dir = plus(3, set->win.corner, \
			fois_x(set->win.horizontal, u), fois_x(set->win.vertical, v));
		r.dir = moins(2, r.dir, set->cam.pos);
		col = plus(2, col, color(set, r));
		s += 0.1;
	}
	col = ranged(divis_x(col, 10));
	return (col);
}
