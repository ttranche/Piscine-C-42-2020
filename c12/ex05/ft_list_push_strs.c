/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:40:10 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/19 10:59:07 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first;

	if (!(first = ft_create_elem(data)))
		return ;
	first->next = *begin_list;
	*begin_list = first;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*current;

	i = 0;
	current = 0;
	while (i < size)
		ft_list_push_front(&current, strs[i++]);
	return (current);
}
