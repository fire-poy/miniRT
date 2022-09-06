/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:06:50 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 08:15:31 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
// - identifiant : cy
// - coordonnées x,y,z du point f50.0,.6
// - Vecteurd’orientation3ddanslerange[-1,1]pourchaqueaxex,y,z:0.0,0.0,1.0 
// - diamètre du cylindre : 14.2
// -  hauteur du cylindre : 21.42
// - Couleurs R,G,B dans le range [0,255] : 10, 0, 255
void	check_hauteur(char **obj_info, char *hauteur, int l_nb)
{
	check_positive_float(obj_info, hauteur, l_nb);
}

void	check_cylindre(char **obj_info, int *q_obj, int l_nb)
{
	if (ft_tab_len(obj_info) != 6)
	{
		free_tab(obj_info);
		print_error_exit("Error\nQuantité des informations ne correspondent pas au Cylindre", l_nb, 1);
	}
	(*q_obj)++;
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_vector_orientation(obj_info, obj_info[2], l_nb);
	check_diameter(obj_info, obj_info[3], l_nb);
	check_hauteur(obj_info, obj_info[4], l_nb);
	check_colors(obj_info, obj_info[5], l_nb);
}

