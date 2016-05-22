/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 16:48:05 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/22 18:17:55 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		get_y(char *str)
{
	int		fd;
	int		ct;
	int		ret;
	char	*line;

	line = NULL;
	ct = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_exiting("File couldn't open");
	while ((ret = ft_gnl(fd, &line)) > 0)
	{
		printf("line == %s\n", line);
		ct++;
		free(line);
	}
	close(fd);
	return (ct);
}

int		get_x(char *str)
{
	int		out;
	int		i;

	out = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			out++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (out);
}

int		**create_tab(char *str)
{
	int		**out;
	int		i;
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	i = 0;
	if (!(out = (int**)malloc(sizeof(int*) * (get_y(str) + 1))))
		return (NULL);
	fd = open(str, O_RDONLY);
	while ((ret = ft_gnl(fd, &line)) > 0)
	{
		if (!(out[i] = (int*)malloc(sizeof(int) * (get_x(line) + 1))))
			return (NULL);//replace by memalloc ?
		i++;
		free(line);
	}
	close(fd);
	return (out);
}

int		main(int ac, char **av)
{
	int		**tab;

	if (ac != 2)
		ft_exiting("Only one arg");
	tab = create_tab(av[1]);
	//leaks because of tab non free
	printf("lol");
	put_data(tab, av[1]);
	print_tab(tab);
	return (0);
}
