/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:18:48 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 08:10:37 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../miniRt.h"
# define AMBIANT 0
# define CAMERA 1
# define LIGHT 2
# define SPHERE 3
# define PLAN 4
# define CYLINDRE 5

# define WHITE_SPACES " \t\v\f\r\n"

typedef struct s_q_obj
{
	int	a; //ambiant
	int	c; //camera
	int	l; //light
	int	sp; //sphere
	int	pl;//plan
	int	cy; //cylindre
	// t_scene *first;
}	t_q_obj;

//mettre scene dans obj?
typedef	struct s_scene t_scene;

struct s_scene
{
	char	*line;
	// char	**infos;
	int		type; //SPHERE
	int		idx;//2 == q_obj.sp
	t_scene	*next;
}	;
//2eme spere
// - [ ] Dessiner le probleme
// 	- [ ] dividir problema en subproblemas
// 	- [ ] **champion du pseudoCode**

int		ft_putnbr(int nb, int fd);
void	print_error_exit(char *e, int line_err, int exit_status);
void	check_arg(const char *scene);
int		is_it_empty_line(char **line, int fd);
int		is_in_range(float n, float min, float max);
void	check_colors(char **obj_info, char *l_color, int l_nb);

//lumiere ambiante
void	check_lumnosité(char **obj_info, char *lumnosité, int l_nb);
void	check_lumiere_ambiente(char **obj_info, int *q_l, int l_nb);

//camera
void	check_coordonees(char **obj_info, char *vector, int l_nb);
void	check_vector_orientation(char **obj_info, char *vector, int l_nb);
void	check_fov(char **obj_info, char *fov, int l_nb);
void	check_camera(char **obj_info, int *q_c, int l_nb);

//lumiere
void	check_lumiere(char **obj_info, int *q_l, int l_nb);

//sphere
void	check_positive_float(char **obj_info, char *diameter, int l_nb);
void	check_diameter(char **obj_info, char *diameter, int l_nb);
void	check_sphere(char **obj_info, int *q_sp, int l_nb);

//plane
void	check_plane(char **obj_info, int *q_obj, int l_nb);

//cylindre
void	check_cylindre(char **obj_info, int *q_obj, int l_nb);

// scene
void	check_scene(char *scene_file, t_q_obj *q_obj);



#endif
