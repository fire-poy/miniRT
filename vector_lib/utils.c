/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:48 by slott             #+#    #+#             */
/*   Updated: 2022/08/29 16:35:13 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

double	length(t_vect v)
{
	double	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (length);
}

t_vect	unit_vector(t_vect v)
{
	return (divis_x(v, length(v)));
}

t_vect	init_vec(double x, double y, double z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

int	to_color(t_vect col)
{
	int	final;

	final = (int)(col.z * 255);
	final += (int)(col.y * 255) << 8;
	final += (int)(col.x * 255) << 16;
	return (final);
}

void	print_vec(t_vect v)
{
	printf("X : %f\n", v.x);
	printf("Y : %f\n", v.y);
	printf("Z : %f\n\n", v.z);
}
