/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:04:41 by mpons             #+#    #+#             */
/*   Updated: 2022/10/01 12:52:37 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

// int	verif_inside_cylindre_body2(t_ray d, const t_obj c, t_ret_ray *ret)
int	inside_limits(t_set *set, t_cyl cyl, t_ray r, float t)
{
	float		hit_point_to_cyl_center;
	float		high_of_hit_point;
	// t_vect		hit_point;
	t_vect		aux;
	// t_vect		vec;

	// hit_point = point_at(r, t);
	// vec = moins(2, hit_point, cyl.pos);
	// hit_point_to_cyl_center = length(vec);
	hit_point_to_cyl_center = vector_distance(point_at(r, t), cyl.pos);
	// hit_point_to_cyl_center = (point_at(r,t), cyl.pos);
	// high_of_hit_point = pow(hit_point_to_cyl_center, 2) - (cyl.r * cyl.r);
	high_of_hit_point = (hit_point_to_cyl_center * hit_point_to_cyl_center) - (cyl.r * cyl.r);
	// pow(cyl.r, 2);
	// pow((cyl.len / 2), 2))
	// if (high_of_hit_point <= ((cyl.len/2) * (cyl.len/2)))
	if (high_of_hit_point <= ((cyl.len / 2) * (cyl.len / 2)))
	{
		set->obj.dist = t;
		aux = moins(2, cyl.pos, point_at(r, t));
		set->normal = cross(aux, cyl.dir);
		set->normal = cross(set->normal, cyl.dir);
		set->normal = unit_vector(set->normal);
		if (dot(set->normal, r.dir) > 0)
			set->normal = invert_vector(set->normal);
		// if (dot(cyl.dir, r.dir) < 0)
		// 	set->normal = invert_vector(set->normal);
		return (1);
	}
	else
		return (0);
}

// delta < 0 : pas de solution dans le domaine reel.  
// delta = 0 : une unique intersection.
// delta > 0 : deux intersection

//normalizer pour avoir bon diamettre ou autre???
int	hit_cyl(t_set *set, t_cyl cyl, t_ray ray)
{
	t_equation	eq;
	
	// set->va = cross(ray.dir, cyl.dir);
	// set->rao = cross(moins(2, ray.pos, cyl.pos), cyl.dir);  
	set->va = cross(ray.dir, unit_vector(cyl.dir));
	set->rao = cross(moins(2, ray.pos, cyl.pos), unit_vector(cyl.dir));  
	eq.a = dot(set->va, set->va);
	eq.b = 2.0 * dot(set->rao, set->va);
	eq.c = dot(set->rao, set->rao) - (cyl.r * cyl.r); 
	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
	if (eq.delta < 0)//pas de solution
		return (0);
	else
	{
		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);//t1
		if (eq.t <= 0)// si eq.t <= 0  t = t2  |  -> t = t2  
			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a); //t2
		if (eq.t < set->obj.dist && eq.t > 0) //si t = 0 ou negative alors return (0)
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
	// float		t;
int	check_cyl(t_set *set, t_cyl cyl, t_ray ray)
{
	int			hit;
	static int	i = 0;

	hit = 0;
	hit += check_cap(set, cyl, cyl.top_center, ray);
	// if (hit > 0)
	// 	printf("hit = %d\n", hit);
	hit += check_cap(set, cyl, cyl.bot_center, ray);
	// if (hit > 0)
	// 	printf("hit = %d\n", hit);
	hit += hit_cyl(set, cyl, ray);
	// if (hit > 0)
	// {
	// 	printf("hit = %d\n", hit);
	// 	printf("-------------\n");
	// }
	if (hit > 1)
	{
		i++;
		// printf("i = %d \n", i);
	}

		// print_error_exit("AAAYYYY", 0, 1);
	return (hit);
}
	// t = hit_cyl(set, cyl, ray);
	// if (t < set->obj.dist && t >= 0)//t>= 0?
	// {
	// 	if (inside_limits(set, cyl, ray))
	// 		return (1); 
	// }
