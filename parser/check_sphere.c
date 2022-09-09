/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:54:44 by mpons             #+#    #+#             */
/*   Updated: 2022/09/09 18:53:29 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_positive_float(char **obj_info, char *diameter, int l_nb)
{
	float	n;

	if (ft_is_it_float(diameter) == 0)
		free_and_error(obj_info, NULL, ERR_FLOAT, l_nb);
	n = atof(diameter);
	if (!is_in_range(n, 0.0f, MAXFLOAT))
		free_and_error(obj_info, NULL, ERR_FLOAT_RANGE, l_nb);
}

void	check_diameter(char **obj_info, char *diameter, int l_nb)
{
	check_positive_float(obj_info, diameter, l_nb);
}

void	check_sphere(char **obj_info, int *q_sp, int l_nb)
{
	if (ft_tab_len(obj_info) != 4)
		free_and_error(obj_info, NULL, ERR_TYPE, l_nb);
	(*q_sp)++;
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_diameter(obj_info, obj_info[2], l_nb);
	check_colors(obj_info, obj_info[3], l_nb);
}
