/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:02:07 by slott             #+#    #+#             */
/*   Updated: 2022/08/29 18:57:11 by slott            ###   ########.fr       */
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
	double	x;
	double	y;
	double	z;
}				t_vect;

t_vect	plus(int n, ...);
t_vect	moins(int n, ...);
t_vect	fois(int n, ...);
t_vect	divis(int n, ...);

t_vect	plus_x(t_vect v1, double t);
t_vect	moins_x(t_vect v1, double t);
t_vect	fois_x(t_vect v1, double t);
t_vect	divis_x(t_vect v1, double t);

double	length(t_vect v);
t_vect	unit_vector(t_vect v);
t_vect	init_vec(double x, double y, double z);
int		to_color(t_vect col);
void	print_vec(t_vect v);

#endif
