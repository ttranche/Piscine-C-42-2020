/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:55:48 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/27 11:52:39 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "map_reader.h"

char		*strappend(char *str, char c, int size)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(size + 2)))
		return (NULL);
	while (i < size)
	{
		new[i] = str[i];
		++i;
	}
	free(str);
	new[i++] = c;
	new[i] = 0;
	return (new);
}

int			is_map_valid(struct s_map *map)
{
	int	i;
	int	j;

	if (map == NULL)
		return (0);
	if (map->c_empty == map->c_rect || map->c_empty == map->c_object ||
		map->c_object == map->c_rect || map->c_rect < ' ' || map->c_rect > '~')
		return (0);
	if (map->height == 0 || map->width == 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((map->map[i][j] != map->c_empty
				&& map->map[i][j] != map->c_object) ||
				map->map[i][j] < ' ' || map->map[i][j] > '~')
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

t_map		*read_data(int file, t_map *map, int current_y)
{
	int		read_o;
	char	buffer;

	if (map->map == NULL || !(map->map[0] = malloc(1)))
		return (NULL);
	map->map[0][0] = 0;
	map->width = 0;
	while ((read_o = read(file, &buffer, 1)) > 0 && buffer != '\n')
		map->map[0] = strappend(map->map[0], buffer, map->width++);
	if (map->height == 1 || read_o == -1)
		return (read_o == -1 || read(file, &buffer, 1) ? NULL : map);
	while ((map->map[current_y] = malloc(map->width + 1))
			&& (read_o = read(file, map->map[current_y], map->width)))
	{
		map->map[current_y++][map->width] = 0;
		buffer = 0;
		if (!read(file, &buffer, 1) || current_y == map->height)
			break ;
	}
	if (!map->map[current_y - 1] || read_o != map->width || buffer != '\n'
		|| read(file, &buffer, 1) || current_y != map->height)
		return (NULL);
	return (map);
}

t_map		*read_header(int file, int size, int i, int read_o)
{
	char	buffer;
	t_map	*map;
	char	*line;

	line = malloc(1);
	if (!(map = malloc(sizeof(struct s_map))) || !(line))
		return (NULL);
	*line = 0;
	map->height = 0;
	map->row = -1;
	while ((read_o = read(file, &buffer, 1)) > 0 && buffer != '\n' && buffer)
		line = strappend(line, buffer, size++);
	while (size-- > 3 && line[i] >= '0' && line[i] <= '9')
		map->height = map->height * 10 + (line[i++] - '0');
	if (map->height == 0)
		return (NULL);
	map->c_empty = line[i++];
	map->c_object = line[i++];
	map->c_rect = line[i];
	map->prevlast = 0;
	map->map = malloc(sizeof(char*) * map->height);
	map = read_data(file, map, 1);
	close(file);
	free(line);
	return (map);
}

t_map		*read_map(char *path)
{
	int		file;
	t_map	*map;

	file = open(path, O_RDONLY);
	if (file == -1)
		return (NULL);
	map = (read_header(file, 0, 0, 0));
	return (map);
}
