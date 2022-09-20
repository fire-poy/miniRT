/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:52:36 by mpons             #+#    #+#             */
/*   Updated: 2022/09/20 15:08:26 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

// int	inter_plane(t_ray d, t_plane plane, t_ret_ray *ret)
// {
//     double        a;
//     double        t;
//     t_vector    oc;
//     t_vector    plane_ori_norm;
//     t_vector    plane_pos_norm;

//     plane_pos_norm = plane.pos;
//     normalize(&plane_pos_norm);
//     plane_ori_norm = plane.orientation;
//     normalize(&plane_ori_norm);
//     a = op_dot(d.d, plane_ori_norm);
//     if (a != 0.0)
//     {
//         oc = op_minus(plane.pos, d.o);
//         t = op_dot(oc, plane_ori_norm) / a;
//         if (t > 0.0)
//         {
//             ret->t = t;
//             ret->p = op_plus(d.o, op_mult(ret->t, d.d));
//              ret->n = plane.orientation;
//            return (1);
//         }
//     }
//     return (0);
// } 

t_vect    invert_vector(t_vect v)
{
	v.x = v.x * -1;
	v.y = v.y * -1;
	v.z = v.z * -1;
	return (v);
}
// 	t_vect	pos;
// 	t_vect	dir;
// 	t_vect	rgb;
// l = unit_vector(r.dir);
float	hit_plan(t_plan pl, t_ray r)
{
	t_vect		po = pl.pos;
	t_vect		n = pl.dir;
	t_vect		lo = r.pos;;//point depart
	t_vect		l = r.dir; //set->cam.dir ->vector unitaire por direc de pixel
	t_vect		polo;
	float		denom;
	float		t;

	denom = dot(l, n);
	// if (denom < 0)
	// {
    //     n = invert_vector(n);
	// 	denom = dot(l, n);
	// }
	if (denom > 1e-6)
	{ 
		polo = moins(2, po,lo);
        t = dot(polo, n) / denom; 
		if (t >= 0)
			return (t);
    } 
	return (-1);
} 
//when the denominator is lower than a very small value 
//we return false (no intersection was found)

void	get_closest_pl(t_set *set, t_ray r)//, int flag)
{
	int		i;
	float	t;

	i = 0;
	if (set->q_obj.pl > 0)
	{
		while (set->plan_list[i].empty == 0)
		{
			t = hit_plan(set->plan_list[i], r);
			// if (t > 0)
			// 	printf("t = %f\n",t);
			if (t < set->obj.dist && t >= 0)
			// if (t < set->obj.dist && t >= 0)
			{
				set->obj.dist = t;
				set->obj.idx = i;
				set->obj.type = PLAN;
				set->obj.col = set->plan_list[i].rgb;
				if (dot(set->plan_list[i].dir, r.dir) > 0)
				{
					// print_vec(set->plan_list[i].dir);
			    	set->normal = invert_vector(set->plan_list[i].dir);
					print_vec(set->normal);
				}
				else
					set->normal = set->plan_list[i].dir;
			}
			i++;
		}
	}
}
