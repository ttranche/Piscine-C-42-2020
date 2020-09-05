/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:53:15 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 20:46:06 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

/*
**	imprime la map
**	ligne par ligne
**	j = ligne ; i = colone;
*/

int		print_map(int **tab, int tabsize)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (i < tabsize)
	{
		j = 0;
		while (j < tabsize)
		{
			temp = '0' + tab[i][j];
			write(1, &temp, 1);
			if (j != (tabsize - 1))
				write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
	return (0);
}

int		**malloc_the_grid(int tabsize)
{
	int **tab;
	int j;
	int i;

	j = 0;
	i = 0;
	if (!(tab = malloc(sizeof(int*) * (tabsize))))
		return (0);
	while (i < tabsize)
	{
		if (!(tab[i] = malloc(sizeof(int) * tabsize)))
			return (0);
		j = 0;
		while (j < tabsize)
		{
			tab[i][j] = 0;
			++j;
		}
		++i;
	}
	return (tab);
}
