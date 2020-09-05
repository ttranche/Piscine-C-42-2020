/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sideview_input_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:08:29 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:22:06 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sideview_input_check.h"

int		**create_side_view_checks(char *arg, int tabsize)
{
	int i;
	int pos;
	int **sidechecks;

	if (!(sidechecks = malloc(sizeof(int*) * (4))))
		return (0);
	i = 0;
	while (i < 4)
		if (!(sidechecks[i++] = malloc(sizeof(int) * tabsize)))
			return (0);
	i = -1;
	pos = 0;
	while (arg[++i] && pos < 4 * tabsize)
	{
		if (i % 2 == 0 && arg[i] >= '1' && arg[i] <= ('0' + tabsize))
		{
			sidechecks[pos / tabsize][pos % tabsize] = arg[i] - '0';
			++pos;
		}
		else if (i % 2 == 0 || (i % 2 == 1 && !(arg[i] == ' ')))
			return (0);
	}
	if (arg[i] != 0 || pos < 4 * tabsize)
		return (0);
	return (sidechecks);
}
