/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:39:17 by slott             #+#    #+#             */
/*   Updated: 2022/08/25 12:19:16 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRt.h"

void	my_pxl_put(t_mlx *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

void	mini_rt(t_mlx *inst)
{
	
}

int	main()
{
	t_mlx	i;

	i.mlx_ptr = mlx_init();
	i.win_ptr = mlx_new_window(i.mlx_ptr, 1800, 900, "MiniRT");
	i.img = mlx_new_image(i.mlx_ptr, 1800, 900);
	i.addr = mlx_get_data_addr(i.img, &i.bpp, &i.line_length, &i.endian);
	mini_rt(&i);
	mlx_key_hook(i.win_ptr, key_hook, NULL);
	mlx_loop(i.mlx_ptr);
	return (0);
}
