/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:05:18 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 11:31:12 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

int		ft_print_addr(int offset, int pos, int op)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (pos < (6 + op) || offset > 16)
		ft_print_addr(offset / 16, pos + 1, op);
	write(1, &hex[offset % 16], 1);
	return (1);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_print_text(char *data, unsigned int size)
{
	unsigned int i;

	i = 0;
	write(1, "  |", 3);
	while (i < size)
	{
		if (data[i] < ' ' || data[i] > '~')
		{
			write(1, ".", 1);
		}
		else
			write(1, &data[i], 1);
		++i;
	}
	write(1, "|", 1);
}

void	ft_print_line(void *addr, unsigned int size, int offset, int op)
{
	unsigned int	i;
	unsigned char	*data;

	data = (unsigned char*)addr;
	i = 0;
	ft_print_addr(offset, 0, op);
	write(1, "  ", 1);
	while (i < 16)
	{
		if (op && i % 8 == 0)
			write(1, " ", 1);
		if (i < size)
			ft_print_hex(data[i]);
		else
			write(1, "  ", 2);
		if (i < 15)
			write(1, " ", 1);
		i++;
	}
	if (op)
		ft_print_text((char*)addr, size);
	write(1, "\n", 1);
}

int		itopen(int *file, char *path)
{
	if (*file != 0)
		close(*file);
	*file = open(path, O_RDONLY);
	return (*file);
}
