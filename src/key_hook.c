/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:51:45 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 17:27:06 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

int	key_hook(int keycode, t_set *set)
{
	if (keycode == 53)
		exit_hook(set);
	return (0);
}

int	exit_hook(t_set *set)
{
	free_scene(set);
	exit(0);
	return (0);
}
