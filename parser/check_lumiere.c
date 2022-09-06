/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lumiere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:42:55 by mpons             #+#    #+#             */
/*   Updated: 2022/09/05 14:54:11 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// L -40.0,50.0,0.0 0.6 10,0,255
// identifiant : L
// coordonnées x,y,z du point Lumière : 0.0,0.0,20.6
// ratio de lumnosité dans le range [0.0,1.0] : 0.6
// (non utilisé dans la partie obligatoire) Couleurs R,G,B dans le range [0- 255] : 10, 0, 255
void	check_lumiere(char **obj_info, int *q_l, int l_nb)
{
	if (ft_tab_len(obj_info) != 3)//4 bonus
	{
		free_tab(obj_info);
		print_error_exit("Error\nQuantité des informations ne correspondent pas au type d'objet", l_nb, 1);
	}
	(*q_l)++;
	if (*q_l > 1)
		print_error_exit("Error\n1 Lumière maximum", l_nb, 1);
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_lumnosité(obj_info, obj_info[2], l_nb);
	// check_colors(obj_info, obj_info[3], l_nb); bonus
}
