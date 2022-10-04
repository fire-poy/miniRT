/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:51:03 by slott             #+#    #+#             */
/*   Updated: 2022/10/03 14:05:46 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

void	fov(t_set *set)
{
	t_vect	vup;
	float	half_width;
	float	half_height;
	float	angle;

	vup = init_vec(0, -1, 0);
	angle = (set->cam.fov * (M_PI / 180)) / 2;
	half_width = tan(angle);
	half_height = half_width / 2;
	set->win.u = unit_vector(cross(vup, set->cam.dir));
	set->win.v = cross(set->cam.dir, set->win.u);
	set->win.corner = moins(4, set->cam.pos, fois_x(set->win.u, \
				half_width), fois_x(set->win.v, half_height), set->cam.dir);
	set->win.horizontal = fois_x(set->win.u, 2.0 * half_width);
	set->win.vertical = fois_x(set->win.v, 2.0 * half_height);
}
