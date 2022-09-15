/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:54:01 by mpons             #+#    #+#             */
/*   Updated: 2022/09/09 18:54:14 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		printf("%s", tab[i]);
		printf("\n");
	}
	printf("fiiiiiiiiin\n");
}

void	print_obj(t_q_obj *q_obj)
{
	printf("obj c = %d\n", q_obj->c);
	printf("obj l = %d\n", q_obj->l);
	printf("obj a = %d\n", q_obj->a);
	printf("obj sp = %d\n", q_obj->sp);
	printf("obj pl = %d\n", q_obj->pl);
	printf("obj cy = %d\n", q_obj->cy);
}
