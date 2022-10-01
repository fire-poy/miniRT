/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:48 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 14:27:22 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

//Initialise un vecteur aux valeurs x, y et z
t_vect	init_vec(float x, float y, float z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

//Convertis un vecteur aux valeurs comprise entre 0 et 1 en int compatible avec
// la fonction my_pxl_put
int	to_color(t_vect col)
{
	int	final;

	if (col.x > 1 || col.y > 1 || col.z > 1)
		col = divis_x(col, 255);
	final = (int)(col.z * 255);
	final += (int)(col.y * 255) << 8;
	final += (int)(col.x * 255) << 16;
	return (final);
}

//Affiche les valeurs d'un vecteur
void	print_vec(t_vect v)
{
	printf("X : %f\n", v.x);
	printf("Y : %f\n", v.y);
	printf("Z : %f\n\n", v.z);
}
