/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:52:36 by mpons             #+#    #+#             */
/*   Updated: 2022/10/01 16:26:01 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

float	hit_plan(t_plan pl, t_ray r)
{
	t_vect		polo;
	float		denom;
	float		t;

	denom = dot(r.dir, pl.dir);
	if (denom != 0)
	{
		polo = moins(2, pl.pos, r.pos);
		t = dot(polo, pl.dir) / denom;
		if (t > 0.0)
			return (t);
	}
	return (-1);
}
