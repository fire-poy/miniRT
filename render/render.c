/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:29:20 by slott             #+#    #+#             */
/*   Updated: 2022/09/15 19:39:47 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

/*
 	Pour fond en degrade
	v1 = init_vec(1, 1, 1);
	v2 = init_vec(0.5, 0.7, 1);
 	u_dir = unit_vector(r.dir);
	t = 0.5 * (u_dir.y + 1);
	col = plus(2, fois_x(v1, 1 - t), fois_x(v2, t));
 */
t_vect	color(t_set *set, t_ray r)
{
	t_vect	col;
	t_vect	v1;
	t_sp	sp;
	int		i;

	i = 0;
// if (get_closest(set, *type) != -1)
	sp = get_closest_sp(set, r, -1, 1000000000);
	if (sp.r != 0)
	{
		v1 = point_at(r, hit_sp(sp, r));
		col = blend_light(set, v1, sp.rgb);
		return (col);
	}
	col = fois_x(set->ambiant.rgb, set->ambiant.light);
	return (col);
}


// typedef struct s_set
// {
// 	t_sp		*sp_list;
// 	t_cyl		*cyl_list;
// 	t_plan		*plan_list;
// 	t_light		light;
// 	t_ambiant	ambiant;
// 	t_camera	cam;
// 	t_win		win;
// 	int			current_id;
	

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
			ray.dir = plus(3, set->win.corner,\
				fois_x(set->win.horizontal, u), fois_x(set->win.vertical, v));
			// print_vec(ray.pos);
			// print_vec(ray.dir);
			my_pxl_put(i, x, y, to_color(color2(set, ray)));
			y++;
		}
		x++;
	}
	// x = 0;
	// while (x < 1800)
	// {
	// 	y = 0;
	// 	while (y < 900)
	// 	{
	// 		u = (float)x / (float)1800;
	// 		v = (float)y / (float)900;
	// 		ray.pos = set->cam.pos;
	// 		ray.dir = plus(3, set->win.corner,\
	// 			fois_x(set->win.horizontal, u), fois_x(set->win.vertical, v));
	// 		// print_vec(ray.pos);
	// 		// print_vec(ray.dir);
	// 		my_pxl_put(i, x, y, to_color(color(set, ray)));
	// 		y++;
	// 	}
	// 	x++;
	// }
	
	mlx_put_image_to_window(i->mlx_ptr, i->win_ptr, i->img, 0, 0);
}
