/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:01:21 by mpons             #+#    #+#             */
/*   Updated: 2022/09/09 18:53:08 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_plane(char **obj_info, int *q_obj, int l_nb)
{
	if (ft_tab_len(obj_info) != 4)
		free_and_error(obj_info, NULL, ERR_TYPE, l_nb);
	(*q_obj)++;
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_vector_orientation(obj_info, obj_info[2], l_nb);
	check_colors(obj_info, obj_info[3], l_nb);
}
