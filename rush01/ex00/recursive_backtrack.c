/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_backtrack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:05:10 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:17:35 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recursive_backtrack.h"
#include "left_to_right_checker.h"
#include "right_to_left_checker.h"
#include "row_utils.h"

/*
**	Lancement des fonctions "left/right" afin de
**	savoir si la grille est valide ou non
*/

int		check(int **sidecheck, int **tab, int pos, int tabsize)
{
	int y;
	int x;
	int valid;
	int	*rotated;

	valid = 1;
	x = pos % tabsize;
	y = pos / tabsize;
	if (!(rotated = rotate_col(pos, tab, tabsize)))
		return (0);
	valid &= is_valid_to_left(sidecheck[2][y], tab[y],
			get_available_nums(tab[y], tabsize), tabsize);
	valid &= is_valid_to_right(sidecheck[3][y], tab[y],
			get_available_nums(tab[y], tabsize), tabsize);
	valid &= is_valid_to_left(sidecheck[0][x], rotated,
			get_available_nums(rotated, tabsize), tabsize);
	valid &= is_valid_to_right(sidecheck[1][x], rotated,
			get_available_nums(rotated, tabsize), tabsize);
	free(rotated);
	return (valid);
}

/*
**	Fonction recursive qui se remet a 0 apres sa
**	recursivite "backtracking"
**	Le backtracking s'effectue de gauche a droite
**	puis enchaine sur la row d'en desous
*/

int		**resolve(int **sidecheck, int **tab, int pos, int tabsize)
{
	int i;
	int x;
	int y;

	i = 0;
	x = pos % tabsize;
	y = pos / tabsize;
	while (++i <= tabsize)
	{
		tab[y][x] = 0;
		if (check_dupe(tab, pos, i, tabsize))
			continue ;
		tab[y][x] = i;
		if (!check(sidecheck, tab, pos, tabsize))
			continue ;
		if (pos + 1 == tabsize * tabsize ||
			resolve(sidecheck, tab, pos + 1, tabsize))
			return (tab);
	}
	tab[y][x] = 0;
	return (0);
}
