/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:01:56 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:19:13 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "row_utils.h"

/*
**	check les cases encore dispo, sinon remplace par des 0
**	renvoie dans l'ordre pour qu'on puisse check les cotes visible
**	des futures posibilites
**
**	2300 -> 1004
**	4000 -> 1230
**	etc..
*/

int		*get_available_nums(int *row, int tabsize)
{
	int i;
	int *nums;

	if (!(nums = malloc(sizeof(int) * tabsize)))
		return (0);
	i = 0;
	while (i < tabsize)
	{
		nums[i] = tabsize - i;
		++i;
	}
	i = 0;
	while (i < tabsize)
	{
		if (row[i] != 0)
			nums[tabsize - row[i]] = 0;
		++i;
	}
	return (nums);
}

/*
**	Retourne la colone en ligne
*/

int		*rotate_col(int pos, int **tab, int tabsize)
{
	int i;
	int *rotated;
	int x;

	x = pos % tabsize;
	if (!(rotated = malloc(sizeof(int) * tabsize)))
		return (0);
	i = 0;
	while (i < tabsize)
	{
		rotated[i] = tab[i][x];
		++i;
	}
	return (rotated);
}

/*
**	Check si meme chiffre dans la colonne et dans la ligne
*/

int		check_dupe(int **tab, int pos, int value, int tabsize)
{
	int x;
	int y;
	int i;

	x = pos % tabsize;
	y = pos / tabsize;
	i = 0;
	while (i < tabsize)
	{
		if (tab[i++][x] == value)
			return (1);
	}
	i = 0;
	while (i < tabsize)
	{
		if (tab[y][i++] == value)
			return (1);
	}
	return (0);
}
