/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:24:02 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/12 09:12:46 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"
#include <unistd.h>

char				*ft_strdupe(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		++i;
	new = malloc(i + 1);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		++i;
	}
	new[i] = 0;
	return (new);
}

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*structs;
	int					i;

	i = 0;
	structs = malloc(sizeof(struct s_stock_str) * (ac + 1));
	while (i < ac)
	{
		structs[i].size = ft_strlen(av[i]);
		structs[i].str = av[i];
		structs[i].copy = ft_strdupe(av[i]);
		++i;
	}
	structs[i].str = 0;
	return (structs);
}
