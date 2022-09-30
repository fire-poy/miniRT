/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:04:41 by mpons             #+#    #+#             */
/*   Updated: 2022/09/30 18:59:53 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

// int	verif_inside_cylindre_body2(t_ray d, const t_obj c, t_ret_ray *ret)
int	inside_limits(t_set *set, t_cyl cyl, t_ray r, float t)
{
	float		hit_point_to_cyl_center;
	float		high_of_hit_point;
	t_vect		hit_point;
	t_vect		aux;
	t_vect		vec;

	hit_point = point_at(r, t);
	vec = moins(2, hit_point, cyl.pos);
	hit_point_to_cyl_center = length(vec);
	// hit_point_to_cyl_center = (point_at(r,t), cyl.pos);
	// high_of_hit_point = pow(hit_point_to_cyl_center, 2) - (cyl.r * cyl.r);
	high_of_hit_point = (hit_point_to_cyl_center * hit_point_to_cyl_center) - (cyl.r * cyl.r);
	// pow(cyl.r, 2);
	// pow((cyl.len / 2), 2))
	// if (high_of_hit_point <= ((cyl.len/2) * (cyl.len/2)))
	if (high_of_hit_point <= ((cyl.len/1.25) * (cyl.len/1.25)))
	{
		set->obj.dist = t;
		aux = moins(2, cyl.pos, point_at(r, t));
		set->normal = cross(aux, cyl.dir);
		set->normal = cross(set->normal, cyl.dir);
		set->normal = unit_vector(set->normal);
		if (dot(cyl.dir, r.dir) < 0)
			set->normal = invert_vector(set->normal);
		return (1);
	}
	else
		return (0);
}

int	hit_cyl(t_set *set, t_cyl cyl, t_ray ray)
{
	t_equation	eq;
	
	set->va = cross(ray.dir, cyl.dir);
	set->rao = cross(moins(2, ray.pos, cyl.pos), cyl.dir);  
	eq.a = dot(set->va, set->va);
	eq.b = 2.0 * dot(set->rao, set->va);
	eq.c = dot(set->rao, set->rao) - (cyl.r * cyl.r); 
	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
	if (eq.delta < 0)
		return (0);
	else
	{
		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
		if (eq.t <= 0)// < 0 emi
			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
		if (eq.t < set->obj.dist && eq.t >= 0)//t > 0?
		{
			if (inside_limits(set, cyl, ray, eq.t))
				return (1);
		}
	}
	return (0);
}

// if (t < cyl[i].t && t > 0)
// cyl[i].t = t;
// float	check_caps(t_set *set, t_cyl cyl, t_ray ray)
int	check_cyl(t_set *set, t_cyl cyl, t_ray ray)
{
	// float		t;
	int			hit;
	
	hit = 0;
	hit += check_cap(set, cyl, cyl.top_center, ray);
	hit += check_cap(set, cyl, cyl.bot_center, ray);
	hit += hit_cyl(set, cyl, ray);
	return (hit);
}
	// t = hit_cyl(set, cyl, ray);
	// if (t < set->obj.dist && t >= 0)//t>= 0?
	// {
	// 	if (inside_limits(set, cyl, ray))
	// 		return (1); 
	// }
