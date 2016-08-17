/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 16:48:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/28 10:57:38 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define LEN 5
# define CST 0.55
# define BEG_X 50
# define BEG_Y 50

typedef struct		s_dot
{
	double			x;
	double			y;
	int				end;
	int				color;
}					t_dot;

typedef struct		s_list
{
	double			x;
	double			y;
	double			z;
	int				color;
	int				end;
	struct s_list	*next;
}					t_list;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				line;
	int				len;
}					t_mlx;

void				draw_line(t_dot a, t_dot b, t_mlx mlx);
void				distrib(t_dot a, t_dot b, t_mlx mlx);
void				draw_vert(t_dot a, t_dot b, t_mlx mlx);
void				prit_list(t_list *tmp);
t_list				*get_data(int fd);
t_list				*last_of(t_list *head);
void				line_check(char *str, t_list **head, int y);
void				add_in_list(t_list **beg, int x, int y, int z);
t_list				*new_node(int x, int y, int z);
int					wild_cases(int ac, char **av);
t_dot				*make_tab(t_list *head);
void				print_tab(t_dot *tab);

#endif
