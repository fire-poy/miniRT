/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:46:21 by slott             #+#    #+#             */
/*   Updated: 2022/09/23 18:30:30 by slott            ###   ########.fr       */
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

t_obj	init_obj(float t_max)
{
	t_obj	obj;

	obj.col = init_vec(0, 0, 0);
	obj.dist = t_max;
	obj.idx = -1;
	obj.type = -1;
	return (obj);
}

// doit rendre le type d'objet et l'index
// arbre de if (type == SPHERE) -> draw_sphere
int	get_closest(t_set *set, t_ray r, float t_max)
{
	int	i;

	i = 0;
	set->obj = init_obj(t_max);
	get_closest_sp(set, r);
	if (set->obj.type == -1)
		return (-1);
	return (0);
}
