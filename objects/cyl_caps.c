/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_caps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:16:08 by mpons             #+#    #+#             */
/*   Updated: 2022/09/30 23:37:01 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

//error viens d'ici??? je crois PAS
float	vector_distance(t_vect a, t_vect b)
{
	t_vect	sust;
	float	dist;

	sust = moins(2, a, b);
	dist = length(sust);
	return (dist);
}

// t_vect	hit_point;
// t_vect	vec;
// hit_point = point_at(r, t);
// vec = moins(2, hit_point, pl_center);
// d_to_center = length(vec);

//problem unit_vector normal cyl ou calcul pos
int	inside_cyl_cap(t_set *set, t_cyl cyl, t_vect pl_center, t_ray r, float t)
{
	float	d_to_center;
	// static	int i =0;

	// t_vect	p;
	// p = plus(2, r.pos, fois_x(r.dir, t));
	// d_to_center = vector_distance(p, pl_center);
	d_to_center = vector_distance(point_at(r, t), pl_center);
	// ret->p = op_plus(d.o, op_mult(ret->t, d.d));
	// if (d_to_center <= cyl.r - 1)
	// if (i = 0)
		// printf()
	if (d_to_center <= cyl.r)
	{			
		// printf("d_to_center %f\n", d_to_center);
		// printf("cyl.r %f\n", cyl.r);
		set->obj.dist = t;
		if (dot(cyl.dir, r.dir) > 0)
			set->normal = invert_vector(cyl.dir);
		else
			set->normal = cyl.dir;
		return (1);
	}
	return (0);
}

// set->normal = unit_vector(cyl.dir);
int	check_cap(t_set *set, t_cyl cyl, t_vect cap_pos, t_ray r)
{
	t_vect		polo;
	float		denom;
	float		t;

	denom = dot(r.dir, cyl.dir);
	if (denom != 0)
	{ 
		polo = moins(2, cap_pos, r.pos);
        t = dot(polo, cyl.dir) / denom; 
		if (t < set->obj.dist && t > 0)
		{
			if (inside_cyl_cap(set, cyl, cap_pos, r, t))
				return (1);
		}
    } 
	return (0);
}


// ///////////////////////////////////////////////////////////////////////
// int	hit_caps(t_ray ray, t_ret_ray *ret_local, t_ret_ray *ret, t_obj *c)
// {
// 	int	intersect_status;

// 	intersect_status = FALSE;
// 	if (inter_plane(ray, *cyl->cylinder_cap, ret_local) && \
// 	verif_inside_cylindre_cap(*ret_local, *c, *cyl->cylinder_cap))
// 		update_ret_cyl(ret, &intersect_status,*ret_local);
// 	cyl->cylinder_cap->pos = cyl->bot_center;
// 	if (inter_plane(ray, *cyl->cylinder_cap, ret_local) && \
// 	verif_inside_cylindre_cap(*ret_local, *c, *cyl->cylinder_cap) \
// 	&& ret_local->t < ret->t)
// 		update_ret_cyl(ret, &intersect_status, *ret_local);
// 	return (intersect_status);
// }

// int	verif_inside_cylindre_body(t_ray d, const t_obj c, t_ret_ray *ret)
// {
// 	float		hit_point_to_cyl_center;
// 	float		cyl_center_to_high_of_hit_point;
// 	t_vect		aux;
// `
// 	hit_point_to_cyl_center = distance_between_two_vectors(c.pos, ret->p);
// 	cyl_center_to_high_of_hit_point = hit_point_to_cyl_center * \
// 	hit_point_to_cyl_center - c.r * 2 * c.r * 2;
// 	if (cyl_center_to_high_of_hit_point <= (c.len / 2) * (c.len / 2))
// 	{
// 		aux = moins(2, c.pos, ret->p);
// 		ret->n = cross(aux, c.dir);
// 		ret->n = cross(ret->n, c.dir);
// 		if (op_dot(ret->n, d.d) > 0)
// 			invert_vector(&ret->n);
// 		normalize(&ret->n);
// 		return (TRUE);
// 	}
// 	else
// 		return (FALSE);
// }

// int	inter_cylinder(t_ray ray, t_obj c, t_ret_ray *ret)
// {
// 	calcul_cyl_centers(&c);
// 	inter_caps(ray, &ret_local, ret, &c);
// 	calcule_a_b_c_delta(ray, &s_inter, c);
// 	if (s_inter.delta < 0)
// 		return (intersect_status);
// 	s_inter.t2 = (-s_inter.b + sqrt(s_inter.delta)) / (2 * s_inter.a);
// 	if (s_inter.t2 < 0)
// 		return (intersect_status);
// 	s_inter.t1 = (-s_inter.b - sqrt(s_inter.delta)) / (2 * s_inter.a);
// 	update_t_value(s_inter, &ret_local);
// 	ret_local.p = plus(2, ray.o, fois_x(ray.d, ret_local.t));
// 	if (verif_inside_cylindre_body(ray, c, &ret_local) == FALSE)
// 		return (intersect_status);
// 	if (ret_local.t < ret->t)
// 		*ret = ret_local;
// 	return (TRUE);
// }
