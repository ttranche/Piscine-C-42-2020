/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:11:20 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/11 09:11:24 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_base_len(char *str)
{
	char	tab[127];
	int		i;
	int		len;

	if (!*str)
		return (0);
	i = 0;
	len = 0;
	while (i < 127)
		tab[i++] = 0;
	while (str[len])
	{
		if (str[len] == '+' || str[len] == '-' || str[len] == '\t'
			|| str[len] == '\n' || str[len] == '\v' || str[len] == '\f'
			|| str[len] == '\r' || str[len] == ' ')
			return (0);
		if (tab[(int)str[len]])
			return (0);
		tab[(int)str[len]] = 1;
		++len;
	}
	return (len <= 1 ? 0 : len);
}
