/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:59:21 by slott             #+#    #+#             */
/*   Updated: 2022/08/31 17:48:45 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRt.h"

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

t_vect	point_at(t_ray r, float t)
{
	t_vect	point;

	point = plus(2, r.pos, fois_x(r.dir, t));
	return (point);
}
