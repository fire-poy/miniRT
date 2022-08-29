/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:39:17 by slott             #+#    #+#             */
/*   Updated: 2022/08/29 18:57:04 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRt.h"

void	my_pxl_put(t_mlx *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

t_vect	color(t_ray r)
{
	t_vect	col;
	t_vect	u_dir;
	t_vect	v1;
	t_vect	v2;
	double	t;

	v1 = init_vec(1, 1, 1);
	v2 = init_vec(0.5, 0.7, 1);
	u_dir = unit_vector(r.dir);
	t = 0.5 * (u_dir.y + 1);
	col = plus(2, fois_x(v1, 1 - t), fois_x(v2, t));
	return (col);
}

int	main()
{
	t_mlx	i;
	t_vect corner;
	t_vect horizontal;
	t_vect vertical;
	t_vect	origin;
	t_ray	ray;
	double	u;
	double	v;
	t_vect	col;

	i.mlx_ptr = mlx_init();
	i.win_ptr = mlx_new_window(i.mlx_ptr, 1800, 900, "MiniRT");
	i.img = mlx_new_image(i.mlx_ptr, 1800, 900);
	i.addr = mlx_get_data_addr(i.img, &i.bpp, &i.line_length, &i.endian);
	corner = init_vec(-2, -1, -1);
	horizontal = init_vec(4, 0, 0);
	vertical = init_vec(0, 2, 0);
	origin = init_vec(0, 0, 0);
	for (int y = 899; y >= 0 ; y--)
	{
		for (int x = 0; x < 1800; x++)
		{
			u = (double)x / (double)1800;
			v = (double)y / (double)900;
			ray.pos = origin;
			ray.dir = plus(3, corner, fois_x(horizontal, u), fois_x(vertical, v));
			col = color(ray);
			my_pxl_put(&i, x, y, to_color(col));
		}
	}
	mlx_put_image_to_window(i.mlx_ptr, i.win_ptr, i.img, 0, 0);
	mlx_key_hook(i.win_ptr, key_hook, NULL);
	mlx_loop(i.mlx_ptr);
	return (0);
}
