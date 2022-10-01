/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:02:07 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 16:29:03 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

t_vect	plus(int n, ...);
t_vect	moins(int n, ...);
t_vect	fois(int n, ...);
t_vect	divis(int n, ...);

t_vect	plus_x(t_vect v1, float t);
t_vect	moins_x(t_vect v1, float t);
t_vect	fois_x(t_vect v1, float t);
t_vect	divis_x(t_vect v1, float t);
t_vect	invert_vector(t_vect v);

float	length(t_vect v);
float	vector_distance(t_vect a, t_vect b);
t_vect	unit_vector(t_vect v);
float	dot(t_vect v1, t_vect v2);
t_vect	cross(t_vect v1, t_vect v2);

t_vect	init_vec(float x, float y, float z);
int		to_color(t_vect col);
void	print_vec(t_vect v);

#endif
