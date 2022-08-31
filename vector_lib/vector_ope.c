/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:49:18 by slott             #+#    #+#             */
/*   Updated: 2022/08/31 17:48:48 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

float	length(t_vect v)
{
	float	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (length);
}

t_vect	unit_vector(t_vect v)
{
	return (divis_x(v, length(v)));
}

float	dot(t_vect v1, t_vect v2)
{
	float	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}
