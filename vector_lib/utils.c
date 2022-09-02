/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:48 by slott             #+#    #+#             */
/*   Updated: 2022/08/31 15:40:46 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

t_vect	init_vec(float x, float y, float z)
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
