/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:50:52 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 08:11:44 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_q_obj	init_q_objs(void)
{
	t_q_obj q_obj;
	
	q_obj.a = 0; //ambiant
	q_obj.c = 0; //camera
	q_obj.l = 0; //light
	q_obj.sp = 0; //sphere
	q_obj.pl = 0; //plan
	q_obj.cy = 0; //cylindre
	return (q_obj);
}

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
	{
		free_tab(obj_info);
		print_error_exit("Error\nType d'objet inconue", l_nb, 1);
	}
	free_tab(obj_info);
}

// print_tab(obj_info);
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

// • Votre programme doit prendre en premier argument une description de scène avec un fichier .rt.
// ◦ Chaque type d’élément est séparé par un ou plusieurs retour(s) à la ligne.
// ◦ Chaque type d’information d’un élément peut être séparé par un ou plusieurs
// espace(s).
// ◦ Les élements peuvent être mis dans n’importe quel ordre dans le fichier.
// ◦ Les éléments qui commencent par une lettre majuscule ne peuvent être déclarés qu’une seule fois dans la scène.
t_set	*parsing(char *scene_file)
{
	// int		fd;
	t_q_obj q_obj;
	// t_set	*set;
	// int		i = 1;

	check_arg(scene_file);
	q_obj = init_q_objs();
	check_scene(scene_file, &q_obj);
	// while (i-- > 0)
	// {
	// }
	return (NULL);
}
// void	ft_read_map(t_map *m)
// {
// 	char	*line;
// 	char	all_char[862];

// 	m->fd = open(m->name, O_RDONLY);
// 	if (m->fd == -1)
// 		fd_error();
// 	line = get_next_line(m->fd);
// 	check_wall(line);
// 	m->len_line = (int)ft_strlen(line) - 1;
// 	while (line)
// 	{
// 		if (line[0] != '1' || line[m->len_line - 1] != '1')
// 			print_error_exit("Error\nmidwall is not closed");
// 		ft_strcat(all_char, line);
// 		m->q_line++;
// 		free(line);
// 		line = get_next_line(m->fd);
// 		if (line && (int)ft_strlen(line) - 1 != m->len_line)
// 			print_error_exit("Error\ndiferents len line");
// 	}
// 	m->map = ft_split(all_char, '\n');
// 	m->fd = close(m->fd);
// 	max_taille(m);
// }	

// //free s == content
// char	**ft_split_from_charset(char *s, char *set)
// {
// 	int		i;
// 	char	**tab_ch;

// 	i = 0;
// 	if (ft_space_out_quotes_found(s, &i, set))
// 	{
// 		tab_ch = malloc(3 * sizeof(char *));
// 		tab_ch[0] = ft_substr(s, 0, i);
// 		while (s[i] == ' ' || s[i] == '\t')
// 			i++;
// 		tab_ch[1] = ft_substr(s, i, (int)ft_strlen - i);
// 		tab_ch[2] = NULL;
// 		free (s);
// 		return (tab_ch);
// 	}
// 	else
// 		return (NULL);
// }


// int	set_type(char *s, int i, char c)
// {
// 	int	type;

// 	if (c == '<')
// 		type = IN_FILE;
// 	if (c == '<' && s[i + 1] == '<')
// 		type = HEREDOC;
// 	if (c == '>')
// 		type = OUT_FILE;
// 	if (c == '>' && s[i + 1] == '>')
// 		type = APPEND;
// 	if (c == '|')
// 		type = PIPE;
// 	return (type);
// }
