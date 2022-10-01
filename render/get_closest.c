/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:46:21 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 17:19:47 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

void	get_closest_sp(t_set *set, t_ray r)
{
	int		i;
	float	t;

	i = 0;
	while (i < set->q_obj.sp)
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

void	get_closest_cyl(t_set *set, t_ray r)
{
	int		i;

	i = 0;
	while (i < set->q_obj.cy)
	{
		if (check_cyl(set, set->cyl_list[i], r) > 0)
		{
			set->obj.idx = i;
			set->obj.type = CYLINDRE;
			set->obj.col = set->cyl_list[i].rgb;
		}
		i++;
	}
}

void	get_closest_pl(t_set *set, t_ray r)
{
	int		i;
	float	t;

	i = 0;
	while (i < set->q_obj.pl)
	{
		t = hit_plan(set->plan_list[i], r);
		if (t < set->obj.dist && t > 0)
		{
			set->obj.dist = t;
			set->obj.idx = i;
			set->obj.type = PLAN;
			set->obj.col = set->plan_list[i].rgb;
			if (dot(set->plan_list[i].dir, r.dir) > 0)
				set->normal = unit_vector(invert_vector(set->plan_list[i].dir));
			else
				set->normal = unit_vector(set->plan_list[i].dir);
		}
		i++;
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
	set->obj = init_obj(t_max);
	get_closest_sp(set, r);
	get_closest_pl(set, r);
	get_closest_cyl(set, r);
	if (set->obj.type == -1)
		return (-1);
	return (0);
}
