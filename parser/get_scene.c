/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:25:26 by mpons             #+#    #+#             */
/*   Updated: 2022/10/04 17:32:17 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../miniRt.h"

void	get_objects(char **obj_info, t_set *set)
{
	if (!ft_strcmp(obj_info[0], "A"))
		get_lumiere_ambiente(set, obj_info);
	else if (!ft_strcmp(obj_info[0], "C"))
		get_camera(set, obj_info);
	else if (!ft_strcmp(obj_info[0], "L"))
		get_lumiere(set, obj_info);
	else if (!ft_strcmp(obj_info[0], "sp"))
		get_sphere(set, obj_info);
	else if (!ft_strcmp(obj_info[0], "pl"))
		get_plane(set, obj_info);
	else if (!ft_strcmp(obj_info[0], "cy"))
		get_cylindre(set, obj_info);
	free_tab(obj_info);
}

void	get_scene(char *scene_file, t_set *set)
{
	char	**obj_info;
	char	*line;
	int		fd;

	fd = open(scene_file, O_RDONLY);
	if (fd == -1)
		print_error_exit("Error\nPendant l'ouverture de fichier", 0, 1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_it_empty_line(&line, fd))
			continue ;
		obj_info = ft_split_set(line, WHITE_SPACES);
		free (line);
		get_objects(obj_info, set);
		line = get_next_line(fd);
	}
	close (fd);
}
