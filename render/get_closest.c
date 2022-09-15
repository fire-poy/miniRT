/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:46:21 by slott             #+#    #+#             */
/*   Updated: 2022/09/15 19:28:00 by mpons            ###   ########.fr       */
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
// typedef	struct s_obj
// {
// 	int	type;
// 	int	idx;
// 	int	dist;
// 	/* data */
// }	t_obj;


// int	get_closest(t_set *set, int *type)
// {
// 	int	i;
// 	int	dist;
// 	t_obj obj;

// 	i = 0;
// 	dist = 0;
// 	while (set->sp_list[i])
// 		get_closest_sp(set, r, -1, 1000000000)//, type); return type
// 		//j'obtiens la sphere la plus pres
// 	while (set->plane_list[i]) //je compare avec tous le plan
// 		get_closest_plane(set, r, 
// 		// si je trouve un qui soit plus pres je remplace type idx et dist
// 	while (set->cyl_list[i])
// 		dist = get_closest_cyl(set, r, -1, 1000000000);
// }
