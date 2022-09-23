/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:03:01 by slott             #+#    #+#             */
/*   Updated: 2022/09/23 17:26:08 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

// Renvoie les coordonees du point en 't' du rayon 'r'

t_vect	point_at(t_ray r, float t)
{
	t_vect	point;

	point = plus(2, r.pos, fois_x(r.dir, t));
	return (point);
}

t_vect	ranged(t_vect v)
{
	if (v.x > 1 || v.y > 1 || v.z > 1)
	{
		if (v.x >= v.y && v.x >= v.z)
			v = divis_x(v, v.x);
		else if (v.y >= v.x && v.y >= v.z)
			v = divis_x(v, v.y);
		else if (v.z >= v.x && v.z >= v.y)
			v = divis_x(v, v.z);
	}
	return (v);
}

float	clamp(float x, float min, float max)
{
	if (x < min)
		x = min;
	else if (x > max)
		x = max;
	return (x);
}

t_vect	col_scaled(t_vect col)
{
	return (divis_x(col, 255));
}
