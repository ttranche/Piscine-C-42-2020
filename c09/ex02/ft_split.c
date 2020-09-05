/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:06:35 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/11 18:18:33 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

char	**ft_create_tab(char *buffer, int size, int i, int count)
{
	char	last;
	char	**tab;

	last = 0;
	while (i < size)
	{
		if (buffer[i] && !last)
			count++;
		last = buffer[i++];
	}
	last = 0;
	i = 0;
	if (!(tab = malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		if (*buffer && !last)
			tab[i++] = ft_strdup(buffer);
		last = *buffer;
		++buffer;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		len;
	char	*buffer;
	int		i;
	int		j;

	len = 0;
	while (str[len])
		++len;
	if (!(buffer = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		j = 0;
		buffer[i] = str[i];
		while (charset[j])
			if (str[i] == charset[j++])
				buffer[i] = 0;
		++i;
	}
	buffer[i] = 0;
	return (ft_create_tab(buffer, len, 0, 0));
}
