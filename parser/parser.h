/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:18:48 by mpons             #+#    #+#             */
/*   Updated: 2022/09/03 21:59:40 by mpons            ###   ########.fr       */
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

typedef struct s_q_obj
{
	int	a; //ambiant
	int	c; //camera
	int	l; //light
	int	sp; //sphere
	int	pl;//plan
	int	cy; //cylindre
}	t_q_obj;

typedef	struct s_scene t_scene;

struct s_scene
{
	char	*line;
	char	**infos;
	int		type; //SPHERE
	int		idx;//2
	t_scene	*next;
}	;
//2eme spere
// - [ ] Dessiner le probleme
// 	- [ ] dividir problema en subproblemas
// 	- [ ] **champion du pseudoCode**

int		ft_putnbr(int nb, int fd);
void	print_error_exit(char *e, int line_err, int exit_status);
void	check_arg(const char *scene);

#endif
