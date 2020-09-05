/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 08:31:11 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/11 12:31:33 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (src[i])
		++i;
	if (!(dup = malloc(i + 1)))
		return (0);
	dup[i] = 0;
	while (i-- > 0)
		dup[i] = src[i];
	return (dup);
}
