/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:01:21 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 08:15:15 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//	 pl 0.0,0.0,-10.0    0.0,1.0,0.0 0,0,225
// 
//  - identifiant : pl
//  - coordonnées x,y,z du point f0.0,0.0
//  - Vecteurd’orientation3ddanslerange[-1,1]pourchaqueaxex,y,z:0.0,0.0,1.0 
//  - Couleurs R,G,B dans le range [0-255] : 0, 0, 255
void	check_plane(char **obj_info, int *q_obj, int l_nb)
{
	if (ft_tab_len(obj_info) != 4)
	{
		free_tab(obj_info);
		print_error_exit("Error\nQuantité des informations ne correspondent pas au type d'objet", l_nb, 1);//plane
	}
	(*q_obj)++;
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_vector_orientation(obj_info, obj_info[2], l_nb);
	check_colors(obj_info, obj_info[3], l_nb);
}
