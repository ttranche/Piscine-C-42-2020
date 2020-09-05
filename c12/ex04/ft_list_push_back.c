/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:25:49 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/19 21:21:51 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;

	last = *begin_list;
	if (!last)
		*begin_list = ft_create_elem(data);
	else
		while (last)
		{
			if (!(last->next))
			{
				last->next = ft_create_elem(data);
				last = (0);
			}
			else
				last = last->next;
		}
}
