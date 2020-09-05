/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:31:59 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/22 16:02:12 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int dir;
	int diff;

	dir = 0;
	i = 0;
	while (i < length - 1)
	{
		diff = f(tab[i], tab[i + 1]);
		if (diff > 0 && dir == 0)
			dir = 1;
		else if (diff < 0 && dir == 0)
			dir = -1;
		if (dir == 1 && diff < 0)
			return (0);
		else if (dir == -1 && diff > 0)
			return (0);
		++i;
	}
	return (1);
}
