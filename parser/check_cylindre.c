/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:06:50 by mpons             #+#    #+#             */
/*   Updated: 2022/09/09 18:52:51 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_hauteur(char **obj_info, char *hauteur, int l_nb)
{
	check_positive_float(obj_info, hauteur, l_nb);
}

void	check_cylindre(char **obj_info, int *q_obj, int l_nb)
{
	if (ft_tab_len(obj_info) != 6)
		free_and_error(obj_info, NULL, ERR_TYPE, l_nb);
	(*q_obj)++;
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_vector_orientation(obj_info, obj_info[2], l_nb);
	check_diameter(obj_info, obj_info[3], l_nb);
	check_hauteur(obj_info, obj_info[4], l_nb);
	check_colors(obj_info, obj_info[5], l_nb);
}
