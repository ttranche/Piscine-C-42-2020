/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 10:41:07 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/11 11:41:53 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *ret;

	if (min >= max || !(ret = malloc(sizeof(*ret) * (max - min))))
		return (0);
	i = 0;
	while (i < (max - min))
	{
		ret[i] = min + i;
		i++;
	}
	return (ret);
}
