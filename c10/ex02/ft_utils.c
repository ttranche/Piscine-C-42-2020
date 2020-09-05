/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:41:14 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/15 19:25:28 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char			*ft_stradd(char *buf, char *add, int *bufsize, int addsize)
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

void			ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void			ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void			print_err(char *binpath, char *filepath)
{
	ft_puterr(basename(binpath));
	ft_puterr(": ");
	ft_puterr(filepath);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}

int				miniatoi(char *str, char *exec)
{
	int res;
	int did;
	int i;

	i = 0;
	did = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		++i;
		did = 1;
	}
	if (!did)
	{
		ft_puterr(basename(exec));
		ft_puterr(": illegal offset -- ");
		ft_puterr(str);
		ft_puterr("\n");
		return (-1);
	}
	return (res);
}
