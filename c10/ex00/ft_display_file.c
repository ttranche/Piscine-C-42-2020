/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:24:09 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 10:31:08 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		ft_display_file(char *path)
{
	int		file;
	int		read_bytes;
	char	buf[16];

	file = open(path, O_RDONLY);
	if (file <= 0)
		return (0);
	while ((read_bytes = read(file, buf, 16)))
	{
		if (read_bytes == -1)
			return (0);
		write(1, buf, read_bytes);
	}
	close(file);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if (!ft_display_file(argv[1]))
		write(2, "Cannot read file.\n", 18);
	return (0);
}
