/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:46:21 by slott             #+#    #+#             */
/*   Updated: 2022/09/17 17:08:21 by mpons            ###   ########.fr       */
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
			}
			i++;
		}
	}
}

t_obj	init_obj(float	t_max)
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
	// get_closest_cyl(set, r);
	// if (set->obj.type == PLAN)
	// 	ft_putendl_fd("je suis un plan", 1);
	if (set->obj.type == -1)
		return (-1);
	return (0);
}

t_vect	color(t_set *set, t_ray r)
{
	t_vect	col;
	t_vect	v1;

	if (get_closest(set, r, 1e+25f) != -1)
	{
		v1 = point_at(r, set->obj.dist);
		col = blend_light(set, v1, set->obj.col);
		return (col);
	}
	// col = init_vec(0,0,0);
	col = fois_x(set->ambiant.rgb, set->ambiant.light);
	return (col);
}
