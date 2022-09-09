/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:51:03 by slott             #+#    #+#             */
/*   Updated: 2022/09/08 15:50:51 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

void	fov(t_set *set)
{
	t_vect	vup;
	float	dist;
	float	angle;

	vup = init_vec(0, 1, 0);
	angle = (set->cam.fov * (M_PI / 180)) / 2;
	dist = 2 / tan(angle);
	set->win.u = unit_vector(cross(vup, set->cam.dir));
	set->win.v = cross(set->cam.dir, set->win.u);
	set->win.horizontal = fois(2, set->win.u, set->win.horizontal);
	set->win.vertical = fois(2, set->win.v, set->win.horizontal);
	set->win.corner = moins(4, set->cam.pos, fois_x(set->win.u, 2),
			fois_x(set->win.v, 1), fois_x(set->cam.dir, dist));
}
