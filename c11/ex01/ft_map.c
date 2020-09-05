/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:21:12 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/17 17:53:07 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *new;
	int i;

	if (length <= 0)
		return (NULL);
	i = 0;
	if (!(new = malloc(sizeof(int) * length)))
		return (NULL);
	while (i < length)
	{
		new[i] = f(tab[i]);
		++i;
	}
	return (new);
}
