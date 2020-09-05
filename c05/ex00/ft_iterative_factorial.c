/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 09:45:34 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/08 11:38:57 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		i;
	int		factorial;

	if (nb < 0)
		return (0);
	factorial = 1;
	i = 1;
	while (i <= nb)
		factorial *= i++;
	return (factorial);
}
