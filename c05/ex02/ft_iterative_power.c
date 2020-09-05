/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:37:43 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/08 12:07:06 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int	i;
	int res;

	if (power < 0)
		return (0);
	i = 0;
	res = 1;
	while (i++ < power)
		res *= nb;
	return (res);
}
