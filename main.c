/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:39:17 by slott             #+#    #+#             */
/*   Updated: 2022/09/06 12:03:20 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

void	my_pxl_put(t_mlx *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

t_vect	color(t_sp sp, t_ray r)
{
	t_vect	col;
	t_vect	u_dir;
	t_vect	v1;
	t_vect	v2;
	float	t;

	v1 = init_vec(1, 1, 1);
	v2 = init_vec(0.5, 0.7, 1);
	t = hit_sp(sp, r);
	if (t > 0.0)
	{
		u_dir = unit_vector(moins(2, point_at(r, t), sp.c));
		return (fois_x(plus_x(u_dir, 1), 0.5));
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
			col = color(set->sp_list[0], ray);
			my_pxl_put(i, x, y, to_color(col));
		}
	}
	mlx_put_image_to_window(i->mlx_ptr, i->win_ptr, i->img, 0, 0);
}

void	init_set(t_set *set)
{
	// set->cam.pos = init_vec(0, 0, 0);
	// set->cam.fov = 90;
	// set->cam.dir = init_vec(0, 0, 1);
	// fov(set);
	set->win.horizontal = init_vec(4, 0, 0);
	set->win.vertical = init_vec(0, 2, 0);
	// set->sp_list = ft_calloc(2, sizeof(t_sp));
	// set->sp_list[0].c = init_vec(0, 0, -3);
	// set->sp_list[0].r = 0.5;
	// set->sp_list[0].rgb = init_vec(1, 0, 0);
}

int	main(int ac, char **av)
{
	t_mlx	i;
	t_set	set;

	if (ac != 2)
		print_error_exit("Usage: ./miniRT scene.rt", 0 , 1);
	parsing(av[1], &set);
	i.mlx_ptr = mlx_init();
	i.win_ptr = mlx_new_window(i.mlx_ptr, 1800, 900, "MiniRT");
	i.img = mlx_new_image(i.mlx_ptr, 1800, 900);
	i.addr = mlx_get_data_addr(i.img, &i.bpp, &i.line_length, &i.endian);
	init_set(&set);
	render(&i, &set);
	mlx_key_hook(i.win_ptr, key_hook, NULL);
	mlx_loop(i.mlx_ptr);
	//free set
	return (0);
}
