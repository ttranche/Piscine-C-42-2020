/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:52:41 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 20:47:24 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "recursive_backtrack.h"
#include "sideview_input_check.h"
#include "map_utils.h"

int		error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	free_mallocs(int **sidechecks, int **tab, int tabsize)
{
	int i;

	i = 0;
	while (i < 4)
		free(sidechecks[i++]);
	i = 0;
	while (i < tabsize)
		free(tab[i++]);
	free(tab);
	free(sidechecks);
}

int		main(int argc, char **argv)
{
	int i;
	int tabsize;
	int **tab;
	int **sidechecks;
	int **result;

	if (argc != 2)
		return (error());
	i = 0;
	tabsize = 4;
	if (!(sidechecks = create_side_view_checks(argv[1], tabsize)))
		return (error());
	if (!(tab = malloc_the_grid(tabsize)))
		return (error());
	result = resolve((int**)sidechecks, tab, 0, tabsize);
	if (result)
		print_map(result, tabsize);
	else
		error();
	free_mallocs(sidechecks, tab, tabsize);
	return (0);
}
