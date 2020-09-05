/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:41:14 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/14 10:52:36 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_mem.h"

int		is_duplicate(char *buf, char *last, int read, int didstar)
{
	int i;
	int dupe;

	i = 0;
	dupe = 1;
	if (didstar == 2)
		dupe = 0;
	while (i < read)
	{
		if (didstar != 2 && buf[i] != last[i])
			dupe = 0;
		last[i] = buf[i];
		++i;
	}
	if (dupe && didstar)
		return (3);
	return (dupe);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int		print_err(char *binpath, char *filepath)
{
	ft_puterr(basename(binpath));
	ft_puterr(": ");
	ft_puterr(filepath);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
	return (1);
}

char	*ft_stradd(char *buf, char *add, int *bufsize, int addsize)
{
	char	*newbuf;
	int		i;

	i = 0;
	if (!(newbuf = malloc((*bufsize + addsize))))
		return (0);
	while (i < *bufsize)
	{
		newbuf[i] = buf[i];
		++i;
	}
	i = 0;
	while (i < addsize)
	{
		newbuf[i + *bufsize] = add[i];
		++i;
	}
	free(buf);
	*bufsize += addsize;
	return (newbuf);
}

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
