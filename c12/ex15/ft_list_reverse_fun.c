/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 20:50:50 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/19 21:24:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*last;

	count = 0;
	last = begin_list;
	while (last)
	{
		last = last->next;
		++count;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	count;
	t_list			*last;

	count = 0;
	last = begin_list;
	while (last)
	{
		if (count == nbr)
			return (last);
		last = last->next;
		++count;
	}
	return (0);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	void	*swap;
	int		size;
	int		i;

	i = 0;
	size = ft_list_size(begin_list);
	while (i < size / 2)
	{
		swap = ft_list_at(begin_list, i)->data;
		ft_list_at(begin_list, i)->data = ft_list_at(begin_list,
			size - 1 - i)->data;
		ft_list_at(begin_list, size - 1 - i)->data = swap;
		++i;
	}
}
