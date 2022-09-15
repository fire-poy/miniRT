/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:03:01 by slott             #+#    #+#             */
/*   Updated: 2022/09/15 17:18:04 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

// Renvoie les coordonees du point en 't' du rayon 'r'

t_vect	point_at(t_ray r, float t)
{
	t_vect	point;

	point = plus(2, r.pos, fois_x(r.dir, t));
	return (point);
}
