/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:30:54 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/08 13:22:22 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		ft_is_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		base_len;
	long	ret;
	int		sign;
	int		base_value;

	if (!(base_len = ft_base_len(base)))
		return (0);
	sign = 1;
	ret = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		++str;
	while (*str == '+' || *str == '-')
	{
		sign *= *str == '-' ? -1 : 1;
		++str;
	}
	while ((base_value = ft_is_base(*str, base)) != -1)
	{
		ret = ret * base_len + base_value;
		++str;
	}
	return ((int)(ret * sign));
}
