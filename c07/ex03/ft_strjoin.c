/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 10:50:30 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/11 09:01:08 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_length(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	length = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			++length;
		if (++i == size)
			break ;
		j = 0;
		while (sep[j++])
			++length;
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		pos;
	int		length;
	char	*ret;

	length = get_length(size, strs, sep);
	ret = malloc(length + 1);
	i = 0;
	pos = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			ret[pos++] = strs[i][j++];
		if (++i == size)
			break ;
		j = 0;
		while (sep[j])
			ret[pos++] = sep[j++];
	}
	ret[pos] = 0;
	return (ret);
}
