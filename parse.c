/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:46:46 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/27 22:06:40 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		wild_cases(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		exiting("One and only one arg please");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exiting("File couldn't open");
	return (fd);
}

t_list	*new_node(int x, int y, int z)
{
	t_list	*out;

	if (!(out = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	out->x = x;
	out->y = y;
	out->z = z;
	out->end = 0;
	out->next = NULL;
	out->color = 0;
	return (out);
}

void	add_in_list(t_list **beg, int x, int y, int z)
{
	if (!(*beg))
		*beg = new_node(x, y, z);
	else if (!(*beg)->next)
		(*beg)->next = new_node(x, y, z);
	else
		add_in_list(&(*beg)->next, x, y, z);
}

t_list	*last_of(t_list *head)
{
	if (!head)
		return (NULL);
	else if (!head->next)
		return (head);
	else
		return (last_of(head->next));
}

void	line_check(char *str, t_list **head, int y)
{
	int		i;
	int		ct;
	int		tmp;

	i = 0;
	ct = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		tmp = ft_atoi(str + i);
		add_in_list(&(*head), ct, y, tmp);
		i += ft_nblen(tmp);
//		if (str[i] && str[i] == ',')
//			last_of(head)->color = ft_get_color(&(str + i));
		ct++;
	}
	last_of(*head)->end = 1;
}

t_list	*get_data(int fd)
{
	char	*line;
	t_list	*out;
	int		y;

	line = NULL;
	out = NULL;
	y = 0;
	while (ft_gnl(fd, &line) > 0)
	{
		line_check(line, &out, y);
		y++;
		free(line);
	}
	close(fd);
	return (out);
}

int		main(int ac, char **av)
{
	t_list	*head;
	int		fd;
	t_dot	*tab;

	fd = wild_cases(ac, av);
	head = get_data(fd);
	tab = make_tab(head);
}
