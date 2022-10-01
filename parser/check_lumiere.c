/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lumiere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:42:55 by mpons             #+#    #+#             */
/*   Updated: 2022/10/01 17:07:41 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// only bonus Couleurs R,G,B dans le range [0- 255] : 10, 0, 255
void	check_lumiere(char **obj_info, int *q_l, int l_nb)
{
	if (ft_tab_len(obj_info) != 3)
		free_and_error(obj_info, NULL, ERR_TYPE, l_nb);
	(*q_l)++;
	if (*q_l > 1)
		free_and_error(obj_info, NULL, "Error\n1 Lumière maximum", l_nb);
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_lumnosite(obj_info, obj_info[2], l_nb);
}
