/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:54:44 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 13:47:11 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// sp 0.0,0.0,20.6 12.6 10,0,255
// - identifiant : sp
// - coordonnées x,y,z du point sphere : 0.0,0.0,20.6
// - the sphere diameter : 12.6
// - Couleurs R,G,B dans le range [0-255] : 10, 0, 255
void	check_positive_float(char **obj_info, char *diameter, int l_nb)
{
	float	n;

	if (ft_is_it_float(diameter) == 0)
	{
		free_tab(obj_info);
		print_error_exit("Error\nNumero n'est pas un float", l_nb, 1);
	}
	n = atof(diameter);
	if (!is_in_range(n, 0.0f, MAXFLOAT))
		print_error_exit("Error\nFloat dehors range [0.0,1.0]", l_nb, 1);
}

void	check_diameter(char **obj_info, char *diameter, int l_nb)
{
	check_positive_float(obj_info, diameter, l_nb);
}

void	check_sphere(char **obj_info, int *q_sp, int l_nb)
{
	if (ft_tab_len(obj_info) != 4)
	{
		free_tab(obj_info);
		print_error_exit(ERR_TYPE, l_nb, 1);
	}
	(*q_sp)++;
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_diameter(obj_info, obj_info[2], l_nb);
	check_colors(obj_info, obj_info[3], l_nb);
}
