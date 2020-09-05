/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:06:46 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/05 09:10:42 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || *str > '~')
			return (0);
		++str;
	}
	return (1);
}
