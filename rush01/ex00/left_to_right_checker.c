/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_to_right_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:56:53 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:14:29 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "left_to_right_checker.h"

int		get_minimum_visible_left(int visible,
				int biggest_visible, int *ava, int tabsize)
{
	int i;

	i = 0;
	while (i < tabsize)
	{
		if (biggest_visible < ava[i])
		{
			visible++;
			biggest_visible = ava[i];
		}
		++i;
	}
	return (visible);
}

int		get_maximum_visible_left(int visible,
				int biggest_visible, int *ava, int tabsize)
{
	int i;

	i = tabsize - 1;
	while (i >= 0)
	{
		if (biggest_visible < ava[i])
		{
			visible++;
			biggest_visible = ava[i];
		}
		--i;
	}
	return (visible);
}

int		get_current_visible_left(int *row, int tabsize, int *biggest)
{
	int i;
	int visible;

	i = 0;
	visible = 0;
	*biggest = 0;
	while (i < tabsize)
	{
		if (*biggest < row[i])
		{
			*biggest = row[i];
			++visible;
		}
		i++;
	}
	return (visible);
}

int		is_valid_to_left(int side, int *row, int *ava, int tabsize)
{
	int maxvisible;
	int minvisible;
	int biggest;
	int visible;

	if (!ava)
		return (0);
	visible = get_current_visible_left(row, tabsize, &biggest);
	maxvisible = get_maximum_visible_left(visible, biggest, ava, tabsize);
	minvisible = get_minimum_visible_left(visible, biggest, ava, tabsize);
	free(ava);
	return (side >= minvisible && side <= maxvisible);
}
