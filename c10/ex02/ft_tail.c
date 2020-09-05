/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:11:09 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 11:10:23 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*createbuffer(int port, int *retsize)
{
	int		read_bytes;
	char	buf[64];
	char	*buffer;
	int		bufsize;

	bufsize = 0;
	*retsize = 0;
	buffer = NULL;
	if (!(buffer = malloc(1)))
		return (0);
	while ((read_bytes = read(port, buf, 64)))
	{
		if (read_bytes == -1)
			return (buffer);
		buffer = ft_stradd(buffer, buf, &bufsize, read_bytes);
	}
	*retsize = bufsize;
	return (buffer);
}

char	*get_file_buf(char *path, int *retsize)
{
	int		file;
	char	*buffer;

	file = open(path, O_RDONLY);
	if (file <= 0 || !(buffer = createbuffer(file, retsize)))
		return (0);
	else
		close(file);
	return (buffer);
}

char	*get_stdin_buf(int *retsize)
{
	char	*buffer;

	if (!(buffer = createbuffer(STDIN_FILENO, retsize)))
		return (0);
	return (buffer);
}

int		do_tail(char *path, int offset, int argc, int i2)
{
	int		i;
	char	*buffer;
	int		bufsize;

	i = 0;
	if (*path && !(buffer = get_file_buf(path, &bufsize)))
		return (0);
	else if (!*path && !(buffer = get_stdin_buf(&bufsize)))
		return (0);
	if (offset > bufsize)
		offset = bufsize;
	if (argc > 4)
	{
		if (i2)
			ft_putstr("\n");
		ft_putstr("==> ");
		ft_putstr(path);
		ft_putstr(" <==\n");
	}
	write(1, (buffer + (bufsize - offset)), offset);
	free(buffer);
	return (1);
}

int		main(int argc, char **argv)
{
	int		c;
	int		i;
	int		first;

	i = 2;
	first = 0;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] != '\0' && i--)
		argv[1] += 2;
	if ((c = miniatoi(argv[i], argv[0])) < 0)
		return (0);
	if (argc <= i + 1)
		do_tail("", c, 0, 0);
	while (++i < argc)
		if (!(do_tail(argv[i], c, argc, first)))
			print_err(argv[0], argv[i]);
		else
			++first;
	return (0);
}
