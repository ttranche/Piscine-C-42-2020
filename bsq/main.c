/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:10:27 by thsembel          #+#    #+#             */
/*   Updated: 2020/08/26 22:50:13 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**	How this bs(q) works:
**
**	Each line gets looped through:
**	The lines get or'd between eachother until there's
**	no space left to fit a square
**
**	Example:
**
**	00000100000 -> 00000100000 -> XXXXX100000 -> 000001XXXX0
**	00100100000 -> 00100100000 -> 001001XXXXX -> 001001XXXX0
**	00001000000 -> 00101100000 -> 001011XXXXX -> 001011XXXX0
**	01001000000 -> 01101100000 -> 011011XXXXX -> 011011XXXX0
**				      i = 4	     x:6 y:0 l:4
**
**	This then repeats for the following lines (offseting this logic by i+1)
**	Intervals with len<(previous max length) won't be processed
**	The mask is also layered so that it removes the last processed row
**	And adds the next one to gain an insane perf boost :D
**
**	@author ttranche
*/

int				main(int argc, char **argv)
{
	int ai;

	ai = 0;
	if (argc == 1)
	{
		if (!process_map(read_header(STDIN_FILENO, 0, 0, 0), -1, 0))
			write(2, "map error\n", 10);
	}
	else
		while (++ai < argc)
		{
			if (!process_map(read_map(argv[ai]), -1, 0))
				write(2, "map error\n", 10);
			if ((argc - 1) != ai && argc > 2)
				write(1, "\n", 1);
		}
	return (0);
}
