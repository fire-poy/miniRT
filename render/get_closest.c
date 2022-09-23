/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:46:21 by slott             #+#    #+#             */
/*   Updated: 2022/09/23 23:07:14 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

void	get_closest_sp(t_set *set, t_ray r)
{
	int		i;
	float	t;

	i = 0;
	if (set->q_obj.sp > 0)
	{
		while (set->sp_list[i].empty == 0)
		{
			t = hit_sp(set->sp_list[i], r);
			if (t < set->obj.dist && t > 0)
			{
				set->obj.dist = t;
				set->obj.idx = i;
				set->obj.type = SPHERE;
				set->obj.col = set->sp_list[i].rgb;
				set->normal = unit_vector(moins(2, point_at(r, t), \
							set->sp_list[i].c));
			}
			i++;
		}
	}
}

void	get_closest_cyl(t_set *set, t_ray r)
{
	int		i;
	float	t;
	t_vect	aux;

	i = 0;
	if (set->q_obj.cy > 0)
	{
		while (set->cyl_list[i].empty == 0)
		{
			t = hit_cyl(set, set->cyl_list[i], r);
			if (t < set->obj.dist && t > 0)
			{
				set->obj.dist = t;
				set->obj.idx = i;
				set->obj.type = CYLINDRE;
				set->obj.col = set->cyl_list[i].rgb;
				aux = moins(2, set->cyl_list[i].pos, point_at(r, t));
				set->normal = cross(aux, set->cyl_list[i].dir);
				set->normal = cross(set->normal, set->cyl_list[i].dir);
				set->normal = unit_vector(set->normal);
			}
			i++;
		}
	}
}
				// set->normal = unit_vector(moins(2, point_at(r, t), set->cyl_list[i].pos));
				// print_vec(set->cyl_list[i].rao);
				// print_vec(set->cyl_list[i].va);
				// print_error_exit("cyl", 0, 2);
				// set->normal = plus(2, set->cyl_list[i].rao, fois_x(set->cyl_list[i].va, t));
				// set->normal = unit_vector(moins(2, set->rao, fois_x(set->va, t)));
				// ret-> = point dintersection avec obj
				// aux = moins(cyl.pos, ret->p);
				// moins(2, point_at(r, t), set->cyl_list[i].c));

void	get_closest_pl(t_set *set, t_ray r)//, int flag)
{
	int		i;
	float	t;

	i = 0;
	// while (i < q_obj.pl)
	if (set->q_obj.pl > 0)
	{
		while (set->plan_list[i].empty == 0)
		{
			t = hit_plan(set->plan_list[i], r);
			if (t < set->obj.dist && t >= 0)
			{
				set->obj.dist = t;
				set->obj.idx = i;
				set->obj.type = PLAN;
				set->obj.col = set->plan_list[i].rgb;
				if (dot(set->plan_list[i].dir, r.dir) < 0)
				{
					// print_vec(set->plan_list[i].dir);
			    	set->normal = invert_vector(set->plan_list[i].dir);
					// print_vec(set->normal);
				}
				else
					set->normal = set->plan_list[i].dir;
			}
			i++;
		}
	}
}

t_obj	init_obj(float t_max)
{
	t_obj	obj;

	obj.col = init_vec(0, 0, 0);
	obj.dist = t_max;
	obj.idx = -1;
	obj.type = -1;
	return (obj);
}

int	get_closest(t_set *set, t_ray r, float t_max)
{
	int	i;

	i = 0;
	set->obj = init_obj(t_max);
	get_closest_sp(set, r);
	get_closest_pl(set, r); 
	get_closest_cyl(set, r);
	if (set->obj.type == -1)
		return (-1);
	return (0);
}
