/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:25:53 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/06 12:10:41 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr(unsigned long offset)
{
	int		i;
	char	adr[17];
	char	*hex;

	adr[16] = 0;
	hex = "0123456789abcdef";
	i = 0;
	while (i <= 16)
	{
		if (offset > 0)
		{
			adr[15 - i] = hex[offset % 16];
			offset /= 16;
		}
		else
		{
			adr[15 - i] = '0';
		}
		++i;
	}
	write(1, adr, 16);
	write(1, ": ", 2);
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
}

void	ft_print_line(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*data;

	data = (unsigned char*)addr;
	i = 0;
	ft_print_addr((unsigned long)addr);
	while (i < 16)
	{
		if (i < size)
			ft_print_hex(data[i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	ft_print_text((char*)addr, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				leftover;

	i = 0;
	leftover = size % 16;
	while (i++ < size / 16)
		ft_print_line(addr + 16 * (i - 1), 16);
	if (leftover)
		ft_print_line(addr + 16 * (i - 1), leftover);
	return (addr);
}
