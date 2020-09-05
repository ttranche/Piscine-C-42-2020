/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:48:09 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/07 09:00:46 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int limit;

	i = 0;
	limit = 0;
	while (dest[i])
		++i;
	while (*src && limit < nb)
	{
		dest[i++] = *src;
		++src;
		++limit;
	}
	dest[i] = 0;
	return (dest);
}
