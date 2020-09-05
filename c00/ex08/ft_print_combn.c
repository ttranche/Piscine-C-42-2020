/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 09:10:16 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/18 15:19:46 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	lnb;
	char	temp;

	lnb = nb;
	if (lnb < 0)
	{
		lnb *= -1;
		write(1, "-", 1);
	}
	if (lnb > 9)
		ft_putnbr(lnb / 10);
	temp = '0' + (char)(lnb % 10);
	write(1, &temp, 1);
}

int		ft_numlen(int num)
{
	int		i;

	i = 0;
	while (num > 0)
	{
		++i;
		num /= 10;
	}
	return (i);
}

int		is_last(int num)
{
	int		i;

	i = 9;
	while (num > 0)
	{
		if (i != num % 10)
			return (0);
		--i;
		num /= 10;
	}
	return (1);
}

void	ft_recursive_comb(int buf, int pos, int n)
{
	char	last_num;
	int		i;

	last_num = (buf / 10) % 10;
	buf += last_num;
	if (!pos)
		buf--;
	while (last_num++ < 9 || (last_num == 10 && n == 1))
	{
		++buf;
		if (pos == n - 1)
		{
			i = n - ft_numlen(buf);
			while (n != 1 && i-- > 0)
				write(1, "0", 1);
			i = n - ft_numlen(buf);
			ft_putnbr(buf);
			if (i != 0 || !is_last(buf))
				write(1, ", ", 2);
		}
		else
			ft_recursive_comb(buf * 10, pos + 1, n);
	}
}

void	ft_print_combn(int n)
{
	ft_recursive_comb(0, 0, n);
}
