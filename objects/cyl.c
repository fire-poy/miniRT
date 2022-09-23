/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:16:08 by mpons             #+#    #+#             */
/*   Updated: 2022/09/23 23:27:39 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

float	hit_cyl(t_set *set, t_cyl cyl, t_ray ray)
{
	t_equation	eq;
	
	set->va = cross(ray.dir, cyl.dir);
	set->rao = cross(moins(2, ray.pos, cyl.pos), cyl.dir);  
	eq.a = dot(set->va, set->va);
	eq.b = 2.0 * dot(set->rao, set->va);
	eq.c = dot(set->rao, set->rao) - (cyl.r * cyl.r); 
	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
	if (eq.delta < 0)
	{
		return (0);
	}
	else
	{
		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
		if (eq.t <= 0)
			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
		return (eq.t);
	}
}

// float	hit_cyl(t_set *set, t_cyl cyl, t_ray ray)
// {
// 	t_equation	eq;
	
// 	set->va = cross(cyl.dir, ray.dir);
// 	set->va = cross(set->va, ray.dir);
// 	eq.a = dot(set->va, set->va);
// 	set->rao = cross(cyl.dir, moins(2, ray.pos, cyl.pos));  
// 	set->rao = cross(set->rao, cyl.dir);  
// 	eq.b = 2.0 * dot(set->rao, set->va);
// 	eq.c = dot(set->rao, set->rao) - (cyl.r * cyl.r); 
// 	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
// 	if (eq.delta < 0)
// 	{
// 		return (0);
// 	}
// 	else
// 	{
// 		// printf("eq.delta = %f\n", eq.delta);
// 		// print_error_exit("cyl", 0, 2);
// 		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
// 		// printf("eq.t = %f\n", eq.t);
// 		if (eq.t <= 0)
// 			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
// 		// printf("eq.t = %f\n", eq.t);
// 		return (eq.t);
// 	}
// }
//je trouve la solution pour la moitie de cylindre

// float	hit_cyl(t_cyl cyl, t_ray ray)
// {
// 	t_equation	eq;
// 	t_vect		va;
// 	t_vect		rao;

// 	va = cross(cyl.dir, ray.dir);
// 	va = cross(va, ray.dir);
// 	eq.a = dot(va, va);
// 	rao = cross(cyl.dir, moins(2, ray.pos, cyl.pos));  
// 	rao = cross(rao, cyl.dir);  
// 	eq.b = 2.0 * dot(rao, va);
// 	eq.c = dot(rao, rao); 
// 	eq.c = eq.c - cyl.r;
// 	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
// 	if (eq.delta < 0)
// 		return (0);
// 	else
// 	{
// 		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
// 		if (eq.t <= 0)
// 			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
// 		return (eq.t);
// 	}
// }
