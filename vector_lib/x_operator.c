/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:23:09 by slott             #+#    #+#             */
/*   Updated: 2022/08/29 14:42:00 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

t_vect	plus_x(t_vect v1, double t)
{
	t_vect	final;

	final.x = v1.x + t;
	final.y = v1.y + t;
	final.z = v1.z + t;
	return (final);
}

t_vect	moins_x(t_vect v1, double t)
{
	t_vect	final;

	final.x = v1.x - t;
	final.y = v1.y - t;
	final.z = v1.z - t;
	return (final);
}

t_vect	fois_x(t_vect v1, double t)
{
	t_vect	final;

	final.x = v1.x * t;
	final.y = v1.y * t;
	final.z = v1.z * t;
	return (final);
}

t_vect	divis_x(t_vect v1, double t)
{
	t_vect	final;

	final.x = v1.x / t;
	final.y = v1.y / t;
	final.z = v1.z / t;
	return (final);
}
