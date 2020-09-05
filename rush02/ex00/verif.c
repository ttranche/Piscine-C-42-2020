/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:16:25 by tmoragli          #+#    #+#             */
/*   Updated: 2020/08/23 20:21:26 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

char	*is_valid_entry(char *orig)
{
	int i;

	i = 0;
	if (!*orig)
		return (NULL);
	while (orig[i])
	{
		if (orig[i] < '0' || orig[i] > '9')
			return (NULL);
		++i;
	}
	return (orig);
}

void	ft_check_output(int *result, char *str)
{
	if (!str)
		*result = 0;
}
