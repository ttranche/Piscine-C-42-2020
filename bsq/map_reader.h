/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:56:07 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/26 09:55:49 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READER_H
# define MAP_READER_H

typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
	int		row;
	int		prevlast;
	char	c_empty;
	char	c_rect;
	char	c_object;
}				t_map;

char			*strappend(char *str, char c, int size);
int				is_map_valid(struct s_map *map);
t_map			*read_data(int file, t_map *map, int current_y);
t_map			*read_header(int file, int size, int i, int read_o);
t_map			*read_map(char *path);

#endif
