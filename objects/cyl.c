/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:04:41 by mpons             #+#    #+#             */
/*   Updated: 2022/10/01 16:51:19 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

int	inside_limits(t_set *set, t_cyl cyl, t_ray r, float t)
{
	float		hit_point_to_cyl_center;
	float		high_of_hit_point;
	t_vect		tmp;

	hit_point_to_cyl_center = vector_distance(point_at(r, t), cyl.pos);
	high_of_hit_point = (pow(hit_point_to_cyl_center, 2) - pow(cyl.r, 2));
	if (high_of_hit_point <= (pow(cyl.len / 2, 2)))
	{
		set->obj.dist = t;
		tmp = moins(2, cyl.pos, point_at(r, t));
		set->normal = cross(tmp, cyl.dir);
		set->normal = cross(set->normal, cyl.dir);
		set->normal = unit_vector(set->normal);
		if (dot(set->normal, r.dir) > 0)
			set->normal = invert_vector(set->normal);
		return (1);
	}
	else
		return (0);
}

int	hit_cyl(t_set *set, t_cyl cyl, t_ray ray)
{
	t_equation	eq;
	t_vect		v;
	t_vect		w;

	v = cross(ray.dir, unit_vector(cyl.dir));
	w = cross(moins(2, ray.pos, cyl.pos), unit_vector(cyl.dir));
	eq.a = dot(v, v);
	eq.b = 2.0 * dot(w, v);
	eq.c = dot(w, w) - pow(cyl.r, 2);
	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
	if (eq.delta < 0)
		return (0);
	else
	{
		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
		if (eq.t <= 0)
			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
		if (eq.t < set->obj.dist && eq.t > 0)
		{
			if (inside_limits(set, cyl, ray, eq.t))
				return (1);
		}
	}
	return (0);
}

int	check_cyl(t_set *set, t_cyl cyl, t_ray ray)
{
	int			hit;

	hit = 0;
	hit += check_cap(set, cyl, cyl.top_center, ray);
	hit += check_cap(set, cyl, cyl.bot_center, ray);
	hit += hit_cyl(set, cyl, ray);
	return (hit);
}
