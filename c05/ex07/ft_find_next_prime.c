/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:37:32 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/10 08:42:07 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;
	int half;

	if (nb % 2 == 0 && nb != 2)
		return (0);
	if (nb % 3 == 0 && nb != 3)
		return (0);
	i = 3;
	half = nb / 2;
	while (i < half)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (nb <= 1 ? 0 : 1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	if (nb < 3)
		return (2);
	if (nb % 2 == 0 && nb != 2)
		++i;
	while (!(ft_is_prime(i)))
		i += 2;
	return (i);
}
