/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:52:31 by tmoragli          #+#    #+#             */
/*   Updated: 2020/08/23 21:00:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check_dict(t_dict *dict)
{
	int i;

	while (dict != NULL)
	{
		i = 0;
		while (dict->name[i])
		{
			if (dict->name[i] < ' ' || dict->name[i] > '~')
				dict->name[i] = ' ';
			++i;
		}
		dict = dict->next;
	}
	return (1);
}

int		check_dupe(t_dict *dict, char *val)
{
	while (dict)
	{
		if (ft_strcmp(val, dict->number) == 0)
			return (1);
		dict = dict->next;
	}
	return (0);
}

int		add_dict(t_dict **dict, char *number, char *name)
{
	t_dict	*new;

	if (!(new = malloc(sizeof(t_dict))))
		return (0);
	new->next = *dict;
	new->name = name;
	new->number = number;
	*dict = new;
	return (1);
}

char	*trim_line(char *str, char **dupe)
{
	int len;

	while (ft_isspace(*str))
		++str;
	len = ft_strlen(str) - 1;
	while (len > 0 && ft_isspace(str[len]))
		str[len--] = 0;
	*dupe = str;
	return (str);
}

int		make_dict(t_line *li, t_dict **dict, char *str, char *dupe)
{
	while (li)
	{
		str = trim_line(li->line, &dupe);
		if (!*str)
		{
			li = li->next;
			continue;
		}
		if (ft_isspace(*str) || *str == ':')
			return (0);
		while (*str >= '0' && *str <= '9')
			++str;
		while (ft_isspace(*str) && !(*str = 0))
			++str;
		if (*str != ':')
			return (0);
		*str = 0;
		while (*str == 0 || ft_isspace(*str))
			++str;
		if (check_dupe(*dict, dupe) || !(add_dict(dict, dupe, str)))
			return (0);
		li = li->next;
	}
	return (1);
}
