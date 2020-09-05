/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:56:29 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/26 18:40:45 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "map_reader.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_interval
{
	int pos;
	int len;
}				t_interval;

typedef struct	s_rect
{
	int len;
	int x;
	int y;
}				t_rect;

void			get_longest_interval(int *row, t_interval *interval,
		int size, t_map *map);
void			mask_tab(t_map *map, char *src, int *dest, int dir);
t_rect			*find_taller_rect(t_map *map, t_rect *rect,
		int *row_mask, t_interval *interval);
void			print_map(t_rect *rect, t_map *map, int x, int y);
int				process_map(t_map *map, int i, int j);

#endif
