/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:36:16 by mpons             #+#    #+#             */
/*   Updated: 2022/10/04 17:32:01 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_it_empty_line(char **line, int fd)
{
	if (*line[0] == '\n' || *line[0] == '#')
	{
		free(*line);
		*line = get_next_line(fd);
		return (1);
	}
	return (0);
}

void	detect_object(char **obj_info, t_q_obj *q_obj, int l_nb)
{
	if (!ft_strcmp(obj_info[0], "A"))
		check_lumiere_ambiente(obj_info, &q_obj->a, l_nb);
	else if (!ft_strcmp(obj_info[0], "C"))
		check_camera(obj_info, &q_obj->c, l_nb);
	else if (!ft_strcmp(obj_info[0], "L"))
		check_lumiere(obj_info, &q_obj->l, l_nb);
	else if (!ft_strcmp(obj_info[0], "sp"))
		check_sphere(obj_info, &q_obj->sp, l_nb);
	else if (!ft_strcmp(obj_info[0], "pl"))
		check_plane(obj_info, &q_obj->pl, l_nb);
	else if (!ft_strcmp(obj_info[0], "cy"))
		check_cylindre(obj_info, &q_obj->cy, l_nb);
	else
		free_and_error(obj_info, NULL, "Error\nType d'objet inconue", l_nb);
	free_tab(obj_info);
}

// • Votre programme doit prendre en premier argument une description de scène
//  avec un fichier .rt.
// ◦ Chaque type d’élément est séparé par un ou plusieurs retour(s) à la ligne.
// ◦ Chaque type d’information d’un élément peut être séparé par un ou plusieurs
// espace(s).
// ◦ Les élements peuvent être mis dans n’importe quel ordre dans le fichier.
// ◦ Les éléments qui commencent par une lettre majuscule ne peuvent être 
// déclarés qu’une seule fois dans la scène.
void	check_scene(char *scene_file, t_q_obj *q_obj)
{
	char	**obj_info;
	char	*line;
	int		l_nb;
	int		fd;

	fd = open(scene_file, O_RDONLY);
	if (fd == -1)
		print_error_exit("Error\nPendant l'ouverture de fichier", 0, 1);
	l_nb = 0;
	line = get_next_line(fd);
	while (line)
	{
		l_nb++;
		if (is_it_empty_line(&line, fd))
			continue ;
		obj_info = ft_split_set(line, WHITE_SPACES);
		free (line);
		detect_object(obj_info, q_obj, l_nb);
		line = get_next_line(fd);
	}
	close (fd);
}
