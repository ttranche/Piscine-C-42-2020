/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:46:05 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/23 18:46:09 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		write_block(char *begin, int size, t_dict *dict, int *first)
{
	int i;
	int s;
	int did;

	i = -1;
	s = 3 - size;
	did = 0;
	while (++i < size)
		if (i + s == 0 && begin[i] >= '1' && begin[i] <= '9' && (did = 1))
		{
			dict->action(first, get_block_name(begin, 1, 1, dict));
			dict->action(first, get_block_name("1", 3, 1, dict));
		}
		else if (i + s == 1 && begin[i] != '0')
		{
			if (begin[i] > '1' && begin[i] <= '9')
				dict->action(first, get_block_name(begin + i, 2, 1, dict));
			else if (begin[i] == '1')
				dict->action(first, get_block_name(begin + i++, 2, 2, dict));
			did = 1;
		}
		else if (i + s == 2 && begin[i] != '0' && (did = 1))
			dict->action(first, get_block_name(begin + i, 1, 1, dict));
	return (did);
}

char	*get_block_name(char *begin, int size, int cmpsize, t_dict *dictionary)
{
	int i;
	int stop;

	while (dictionary)
	{
		if (ft_strlen(dictionary->number) == size &&
				ft_strncmp(begin, dictionary->number, cmpsize) == 0)
		{
			i = cmpsize - 1;
			stop = 0;
			while (++i < size)
				if (dictionary->number[i] && dictionary->number[i] != '0')
					stop = 1;
			if (!stop)
				return (dictionary->name);
		}
		dictionary = dictionary->next;
	}
	return (NULL);
}
