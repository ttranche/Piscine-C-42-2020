/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_to_left_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:00:38 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:15:51 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "right_to_left_checker.h"

int		get_maximum_visible_right(int *row, int *ava, int tabsize)
{
	int maxvisible;
	int biggest;
	int i;

	i = tabsize - 1;
	maxvisible = 0;
	biggest = 0;
	while (i >= 0)
		if (biggest < ava[i--])
		{
			biggest = ava[i + 1];
			++maxvisible;
		}
	i = tabsize - 1;
	while (i >= 0)
		if (biggest < row[i--])
		{
			biggest = row[i + 1];
			++maxvisible;
		}
	return (maxvisible);
}

int		get_minimum_visible_right(int *row, int *ava, int tabsize)
{
	int minvisible;
	int biggest;
	int i;

	biggest = 0;
	minvisible = 0;
	i = 0;
	while (i < tabsize)
		if (biggest < ava[i++])
		{
			biggest = ava[i - 1];
			++minvisible;
		}
	i = tabsize - 1;
	while (i >= 0)
		if (biggest < row[i--])
		{
			biggest = row[i + 1];
			++minvisible;
		}
	return (minvisible);
}

/*
**	check dans l'autre sens la visibilite max et la visibilite minimum
*/

int		is_valid_to_right(int side, int *row, int *ava, int tabsize)
{
	int maxvisible;
	int minvisible;

	if (!ava)
		return (0);
	maxvisible = get_maximum_visible_right(row, ava, tabsize);
	minvisible = get_minimum_visible_right(row, ava, tabsize);
	free(ava);
	return (side >= minvisible && side <= maxvisible);
}
