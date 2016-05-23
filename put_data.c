/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 18:04:56 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/23 08:43:55 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	put_str(int *rank, char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		rank[x] = ft_atoi(str + i);
		i += ft_nblen(rank[x]);
		x++;
	}
	rank[x] = END;
}

void	put_data(int **tab, char *str)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	fd = open(str, O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		put_str(tab[i], line);
		i++;
		free(line);
	}
	tab[i] = NULL;
}

void	print_tab(int **tab)
{
	int		i;
	int		x;

	i = 0;
	while (tab[i])
	{
		x = 0;
		printf("\nline new:");
		while (tab[i][x] != END)
		{
			printf("%d ", tab[i][x]);
			x++;
		}
		printf("%d ", tab[i][x]);
		i++;
	}
}
