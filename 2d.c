/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 08:12:05 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/23 13:02:46 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_coord		*get_tab(int **tab)
{
	t_coord	*lol;
	int		i;
	int		ct;
	int		x;

	i = 0;
	ct = 0;
	while (tab[i])
	{
		x = 0;
		while (tab[i][x] != END)
		{
			x++;
			ct++;
		}
		i++;
	}
	if (!(lol = (t_coord*)malloc(sizeof(t_coord) * (ct + 1))))
		return (NULL);
	return (lol);
}

t_coord	*fill_up(int **tab)
{
	int		x;
	int		y;
	t_coord	*out;
	int		ct;

	out = get_tab(tab);
	y = 0;
	ct = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x] != END)
		{
			(out + ct)->x = (((5 * ((BEG_X + x * 20) - 1)) / (5 + tab[y][x])) + 1);
			(out + ct)->y = (((5 * ((BEG_Y + y * 20) - 1)) / (5 + tab[y][x])) + 1);
			x++;
			ct++;
		}
		y++;
	}
	(out + ct)->x = END;
	return (out);
}

void	draw_2d(t_coord *coord)
{
	void	*mlx;
	void	*win;
	int		ct;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "swaggg");
	ct = 0;
	while ((coord + ct)->x != END)
	{
		mlx_pixel_put(mlx, win, (coord + ct)->x, (coord + ct)->y, 0xFF00FF);
		ct++;
	}
	mlx_loop(mlx);
}
