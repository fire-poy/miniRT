/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:51:03 by slott             #+#    #+#             */
/*   Updated: 2022/09/23 20:06:06 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

void	fov(t_set *set)
{
	t_vect	vup;
	float	half_width;
	float	half_height;
	float	angle;

	vup = init_vec(0, 1, 0);
	// vup = set->cam.dir;
	angle = (set->cam.fov * (M_PI / 180)) / 2;//convertion radiant et moitie ecran
	half_width = tan(angle);//trigo pour obtenir la longeur de l'ecran
	half_height = half_width / 2;
	set->win.u = unit_vector(cross(vup, set->cam.dir));//produit vect pour obtenir le horizontal et vertical
	set->win.v = cross(set->cam.dir, set->win.u);
	//en bas a gauche
	set->win.corner = moins(4, set->cam.pos, fois_x(set->win.u, \
				half_width), fois_x(set->win.v, half_height), set->cam.dir);
	set->win.horizontal = fois_x(set->win.u, 2.0 * half_width);
	set->win.vertical = fois_x(set->win.v, 2.0 * half_height);
}
