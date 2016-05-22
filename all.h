/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 16:48:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/22 18:15:12 by thifranc         ###   ########.fr       */
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

void	put_data(int **tab, char *str);
void	print_tab(int **tab);
void	put_str(int *rank, char *str);
int		get_y(char *str);
int		get_x(char *str);
int		**create_tab(char *str);


#endif
