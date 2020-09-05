/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:34:46 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/19 21:22:51 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*last;

	last = *begin_list1;
	while (last)
	{
		if (!(last->next))
		{
			last->next = begin_list2;
			break ;
		}
		last = last->next;
	}
	if (!(last))
		*begin_list1 = begin_list2;
}
