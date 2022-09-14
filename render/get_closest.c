/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:46:21 by slott             #+#    #+#             */
/*   Updated: 2022/09/14 14:25:54 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

t_sp	get_closest_sp(t_set *set, t_ray r, int ex, float t_max)
{
	int		i;
	float	t;
	float	max;
	int		id;
	t_sp	empty;

	i = 0;
	empty.r = 0;
	empty.c = init_vec(0, 0, 0);
	if (!set->sp_list[0].r)
		return (empty);
	max = t_max;
	id = 0;
	while (set->sp_list[i].r)
	{
		t = hit_sp(set->sp_list[i], r);
		if (t < max && t > 0 && ex != i)
		{
			max = t;
			id = i;
		}
		i++;
	}
	if (max == t_max)
		return (empty);
	set->current_id = id;
	return (set->sp_list[id]);
}
