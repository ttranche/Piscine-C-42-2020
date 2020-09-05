/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:55:03 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/27 08:52:28 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h"
#include "bsq.h"

void			get_longest_interval(int *row, t_interval *interval,
										int size, t_map *map)
{
	int		current;
	int		i;

	interval->len = 0;
	interval->pos = 0;
	i = 0;
	current = 0;
	while (i < map->width)
	{
		if (row[i] == map->c_empty)
			++current;
		else
			current = 0;
		if (current > interval->len)
		{
			interval->len = current;
			interval->pos = 1 + i - current;
			if (interval->len == size)
				return ;
		}
		++i;
	}
}

void			mask_tab(t_map *map, char *src, int *dest, int dir)
{
	int		i;

	i = 0;
	while (i < map->width)
	{
		if (src[i] != map->c_empty)
			dest[i] += dir;
		++i;
	}
}

struct s_rect	*find_taller_rect(t_map *map, t_rect *rect,
									int *row_mask, t_interval *interval)
{
	int		i;
	int		y;

	y = 0;
	i = ++(map->row) + map->prevlast;
	while (i < map->height && (interval->len >= (i - map->row)
		|| (y == 0)))
	{
		mask_tab(map, map->map[i++], row_mask, 1);
		y = 1;
		get_longest_interval(row_mask, interval, i - map->row, map);
		map->prevlast = i - map->row - 1;
		if (interval->len > rect->len && rect->len < i - map->row)
		{
			rect->len = i - map->row;
			rect->x = interval->pos;
			rect->y = map->row;
		}
	}
	if (y)
		mask_tab(map, map->map[map->row], row_mask, -1);
	return (rect);
}

void			print_map(t_rect *rect, t_map *map, int x, int y)
{
	char	*xbuf;

	if (!(xbuf = malloc(rect->len)))
		return ;
	while (x < rect->len)
		xbuf[x++] = map->c_rect;
	while (++y < map->height)
	{
		if (rect->y <= y && y < rect->y + rect->len)
		{
			write(1, map->map[y], rect->x);
			write(1, xbuf, rect->len);
			write(1, (map->map[y] + (rect->x + rect->len)),
					map->width - (rect->x + rect->len));
		}
		else
			write(1, map->map[y], map->width);
		write(1, "\n", 1);
	}
	y = 0;
	while (y < map->height)
		free(map->map[y++]);
	free(map->map);
	free(map);
	free(xbuf);
}

int				process_map(t_map *map, int i, int j)
{
	t_rect		*rect;
	t_interval	*interval;
	int			*row_mask;

	if (!(interval = malloc(sizeof(struct s_interval))))
		return (0);
	if (is_map_valid(map))
	{
		rect = malloc(sizeof(struct s_rect));
		row_mask = malloc(sizeof(int) * map->width);
		if (interval == NULL || rect == NULL || row_mask == NULL)
			return (0);
		interval->len = 0;
		rect->len = 0;
		while (j < map->width)
			row_mask[j++] = map->c_empty;
		while (++i <= (map->height - rect->len))
			find_taller_rect(map, rect, row_mask, interval);
		print_map(rect, map, 0, -1);
		free(row_mask);
		free(rect);
	}
	free(interval);
	return (i >= 0 ? 1 : 0);
}
