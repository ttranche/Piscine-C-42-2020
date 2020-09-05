/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 09:01:47 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/18 15:20:06 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long lnb;
	char temp;

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

void	ft_print_comb2(void)
{
	int first;
	int second;

	first = 0;
	while (first <= 99)
	{
		second = first + 1;
		while (second <= 99)
		{
			if (first <= 9)
				write(1, "0", 1);
			ft_putnbr(first);
			write(1, " 0", second > 9 ? 1 : 2);
			ft_putnbr(second);
			if (first != 98 || second != 99)
				write(1, ", ", 2);
			++second;
		}
		++first;
	}
}

int main()
{ft_print_comb2();return 0;}
