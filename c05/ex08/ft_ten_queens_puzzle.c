/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:43:39 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/08 12:16:19 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_contains(int *rows, int pos, int value)
{
	int i;

	i = 0;
	while (i < pos)
		if (rows[i++] == value)
			return (1);
	return (0);
}

int		ft_diagonal(int *rows, int pos, int value)
{
	int i;
	int delta;

	i = pos;
	while (i > 0)
	{
		delta = rows[i - 1] - value;
		if (delta < 0)
			delta *= -1;
		delta -= pos - i + 1;
		if (!delta)
			return (1);
		--i;
	}
	return (0);
}

int		recursive_queen(int *rows, int pos)
{
	int		count;
	int		i;
	int		j;
	char	c;

	i = 0;
	count = 0;
	while (i <= 9)
	{
		if ((ft_contains(rows, pos, i) || ft_diagonal(rows, pos, i)) && ++i)
			continue ;
		rows[pos] = i;
		if (pos == 9)
		{
			j = 0;
			while (j < 10 && (c = rows[j++] + '0'))
				write(1, &c, 1);
			++count;
			write(1, "\n", 1);
		}
		else
			count += recursive_queen(rows, pos + 1);
		++i;
	}
	return (count);
}

int		ft_ten_queens_puzzle(void)
{
	int tab[10];
	int i;

	i = 0;
	while (i < 10)
		tab[i++] = 0;
	return (recursive_queen(tab, 0));
}
