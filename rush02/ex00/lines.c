/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:45:35 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/23 18:45:49 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		add_line(t_line **line, char *data)
{
	t_line	*new;

	if (!(new = malloc(sizeof(t_line))))
		return (0);
	new->next = *line;
	new->line = data;
	*line = new;
	return (1);
}

int		load_file(char *path, t_line **first, int size)
{
	int		file;
	char	*dyn_buffer;
	int		read_bytes;
	char	c;

	read_bytes = 0;
	dyn_buffer = malloc(1);
	if ((file = open(path, O_RDONLY)) == -1 || !dyn_buffer)
		return (0);
	dyn_buffer[0] = 0;
	while ((read_bytes = read(file, &c, 1)) != 0)
		if (read_bytes == -1 || c == 0)
			return (0);
		else if (c == '\n')
		{
			if (!add_line(first, dyn_buffer) || !(dyn_buffer = malloc(1)))
				return (0);
			dyn_buffer[0] = 0;
			(*first)->size = size;
			size = 0;
		}
		else
			dyn_buffer = ft_strcat(dyn_buffer, c, size++);
	free(dyn_buffer);
	return (1);
}
