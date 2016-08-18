/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:11:00 by thifranc          #+#    #+#             */
/*   Updated: 2016/08/18 08:57:44 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		ft_quit(int key)
{
	if (key == 53)
		exit(-1);
	return (0);
}

int		ft_atoi_error(char *str)
{
	int i;
	int flag;
	int nb;

	i = 0;
	nb = 0;
	flag = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		flag = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		exiting("Data map not well formated, only numbers please\n");
	if (flag == 1)
		nb = -nb;
	return (nb);
}

void	put_dots(t_dot *dot, t_mlx mlx)
{
	int		ct;

	ct = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1600, 1600, "lol");
	while (!(dot + ct)->end)
	{
		distrib(*(dot + ct), *(dot + ct + 1), mlx);
		if ((ct / mlx.len) != mlx.line - 1)
			distrib(*(dot + ct), *(dot + ct + mlx.len), mlx);
		ct++;
	}
	mlx_key_hook(mlx.win, ft_quit, NULL);
	mlx_loop(mlx.mlx);
}

t_dot	*make_tab(t_list *head)
{
	t_dot	*out;
	t_mlx	data;
	int		ct;

	ct = 0;
	if (!(out = (t_dot*)malloc(sizeof(t_dot) *
			((last_of(head)->x + 1) * (last_of(head)->y + 1) + 1))))
		return (NULL);
	data.len = last_of(head)->x + 1;
	data.line = last_of(head)->y + 1;
	while (head)
	{
		(out + ct)->x = BEG_X + LEN * head->x + CST * head->z * LEN;
		(out + ct)->y = BEG_Y + LEN * head->y + (CST / 2) * head->z * LEN;
		(out + ct)->end = 0;
		(out + ct)->color = 0;
		head = head->next;
		ct++;
	}
	(out + ct)->end = 1;
	put_dots(out, data);
	return (out);
}
