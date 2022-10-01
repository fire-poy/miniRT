/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:59:21 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 14:33:30 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

// Calcule si un rayon "ray" traverse ou non la sphere "sp" 
// Renvoie la ou les valeurs 't' pour lesquels le rayon touche la sphere
float	hit_sp(t_sp sp, t_ray ray)
{
	t_equation	eq;

	eq.oc = moins(2, ray.pos, sp.c);
	eq.a = dot(ray.dir, ray.dir);
	eq.b = 2.0 * dot(ray.dir, eq.oc);
	eq.c = dot(eq.oc, eq.oc) - (sp.r * sp.r);
	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
	if (eq.delta < 0)
		return (0);
	else
	{
		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
		if (eq.t <= 0)
			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
		return (eq.t);
	}
}
