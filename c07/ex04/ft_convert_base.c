/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:48:05 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/22 11:46:53 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_len(char *str);

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

char	*ft_strcat(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		++i;
	new = malloc(i + 2);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		++i;
	}
	new[i++] = c;
	new[i] = 0;
	free(str);
	return (new);
}

char	*ft_base_str(int nbr, char *base, char *buffer)
{
	long	nb;
	int		base_len;
	char	temp;

	if (!(base_len = ft_base_len(base)))
		return (0);
	nb = nbr;
	if (nb < 0)
	{
		buffer = ft_strcat(buffer, '-');
		nb *= -1;
	}
	if (nb > (base_len - 1))
		buffer = ft_base_str(nb / base_len, base, buffer);
	temp = base[(int)(nb % base_len)];
	return (ft_strcat(buffer, temp));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*tempres;

	if (!(ft_base_len(base_from)) || !(ft_base_len(base_to)))
		return (0);
	tempres = malloc(1);
	tempres[0] = 0;
	nb = ft_atoi_base(nbr, base_from);
	tempres = ft_base_str(nb, base_to, tempres);
	return (tempres);
}
