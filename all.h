/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 16:48:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/23 18:02:00 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define END -666
# define BEG_X 100
# define BEG_Y 100

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

void	put_data(int **tab, char *str);
void	print_tab(int **tab);
void	put_str(int *rank, char *str);
int		get_y(char *str);
int		get_x(char *str);
int		**create_tab(char *str);

void	draw_2d(t_coord *coord);
void	draw_horizont(t_coord a, t_coord b, int flag, void *mlx, void *win);
void	draw_line(t_coord a, t_coord b, void *mlx, void *win);
t_coord	*get_tab(int **tab);
t_coord	*fill_up(int **tab);

#endif
