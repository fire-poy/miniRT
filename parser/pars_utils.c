/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:34:30 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 10:35:14 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_tab(char **tab)
{
	int i = -1;

	while (tab[++i])
	{
		printf("%s", tab[i]);
		printf("\n");
	}
	printf("fiiiiiiiiin\n");
}

void	print_obj(t_q_obj *q_obj)
{
	printf("obj c = %d\n", q_obj->c); //camera
	printf("obj l = %d\n", q_obj->l); //light
	printf("obj a = %d\n", q_obj->a); //ambiant
	printf("obj sp = %d\n", q_obj->sp); //sphere
	printf("obj pl = %d\n", q_obj->pl); //plan
	printf("obj cy = %d\n", q_obj->cy); //cylindre
}
