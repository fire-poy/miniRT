/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:39:17 by slott             #+#    #+#             */
/*   Updated: 2022/09/14 14:25:38 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

void	my_pxl_put(t_mlx *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

//free_set at the end
int	main(int ac, char **av)
{
	t_mlx	i;
	t_set	set;

	if (ac != 2)
		print_error_exit("Usage: ./miniRT scene.rt", 0, 1);
	i.mlx_ptr = mlx_init();
	i.win_ptr = mlx_new_window(i.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "MiniRT");
	i.img = mlx_new_image(i.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	i.addr = mlx_get_data_addr(i.img, &i.bpp, &i.line_length, &i.endian);
	set.win.horizontal = init_vec(4, 0, 0);
	set.win.vertical = init_vec(0, 2, 0);
	parsing(av[1], &set);
	render(&i, &set);
	mlx_key_hook(i.win_ptr, key_hook, NULL);
	mlx_hook(i.win_ptr, 17, 0, exit_hook, NULL);
	mlx_loop(i.mlx_ptr);
	return (0);
}
