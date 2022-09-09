/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:59:21 by slott             #+#    #+#             */
/*   Updated: 2022/09/09 19:32:11 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

// Calcule si un rayon "ray" traverse ou non la sphere "sp"
// Renvoie la ou les valeurs 't' pour lesquels le rayon touche la sphere
float	hit_sp(t_sp sp, t_ray ray)
{
	t_vect	oc;
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t;

	oc = moins(2, ray.pos, sp.c);
	a = dot(ray.dir, ray.dir);
	b = 2.0 * dot(ray.dir, oc);
	c = dot(oc, oc) - (sp.r * sp.r);
	delta = (b * b) - (4.0 * a * c);
	if (delta < 0)
		return (0);
	else
	{
		t = (-b - sqrt(delta)) / 2 * a;
		return (t);
	}
}
