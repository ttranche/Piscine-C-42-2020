/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:38:13 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/14 09:59:58 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int		output_port(int port)
{
	int		read_bytes;
	char	buf[16];

	while ((read_bytes = read(port, buf, 16)))
	{
		if (read_bytes == -1)
			return (0);
		write(1, buf, read_bytes);
	}
	return (1);
}

int		print_file(char *path)
{
	int		file;

	file = open(path, O_RDONLY);
	if (file <= 0 || !output_port(file))
		return (0);
	else
		close(file);
	return (1);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	print_err(char *binpath, char *filepath)
{
	ft_puterr(basename(binpath));
	ft_puterr(": ");
	ft_puterr(filepath);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
		output_port(STDIN_FILENO);
	else
		while (++i < argc)
			if (!print_file(argv[i]))
				print_err(argv[0], argv[i]);
	return (0);
}
