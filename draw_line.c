/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:47:23 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/27 19:26:45 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	distrib(t_dot beg, t_dot end, t_mlx mlx)
{
	if (beg.x <= end.x && (end.x - beg.x) >= fabs(end.y - beg.y))
		draw_line(beg, end, mlx);
	else if (beg.x > end.x && (end.x - beg.x) >= fabs(end.y - beg.y))
		draw_line(end, beg, mlx);
	else if (beg.y <= end.y && (end.y - beg.y) >= fabs(end.x - beg.x))
		draw_vert(beg, end, mlx);
	else if (beg.y > end.y && (end.y - beg.y) >= fabs(end.x - beg.x))
		draw_vert(end, beg, mlx);
}

void	draw_line(t_dot beg, t_dot end, t_mlx mlx)
{
	int		x;
	int		y;

	x = beg.x;
	while (x != (int)end.x)
	{
		y = beg.y + ((end.y - beg.y) * (x - beg.x)) / (end.x - beg.x);
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, 0xFFFFFF);
		x++;
	}
}

void	draw_vert(t_dot beg, t_dot end, t_mlx mlx)
{
	int		x;
	int		y;

	y = beg.y;
	while (y != (int)end.y)
	{
		x = beg.x + ((end.x - beg.x) * (y - beg.y)) / (end.y - beg.y);
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, 0xFFFFFF);
		y++;
	}
}
