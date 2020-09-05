/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:48:28 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/08 14:20:42 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_base_len(char *str)
{
	char	tab[127];
	int		i;
	int		len;

	if (!*str)
		return (0);
	i = 0;
	len = 0;
	while (i < 127)
		tab[i++] = 0;
	while (str[len])
	{
		if (str[len] == '+' || str[len] == '-')
			return (0);
		if (tab[(int)str[len]])
			return (0);
		tab[(int)str[len]] = 1;
		++len;
	}
	return (len <= 1 ? 0 : len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		base_len;
	char	temp;

	if (!(base_len = ft_base_len(base)))
		return ;
	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > (base_len - 1))
		ft_putnbr_base(nb / base_len, base);
	temp = base[(int)(nb % base_len)];
	write(1, &temp, 1);
}
