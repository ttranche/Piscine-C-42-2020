/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:06:40 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/07 08:36:14 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i])
		++i;
	while (src[j])
		++j;
	j += size < i ? size : i;
	while (*src && i < (size - 1) && size != 0)
	{
		dest[i] = *src;
		++i;
		++src;
	}
	dest[i] = 0;
	return (j);
}
