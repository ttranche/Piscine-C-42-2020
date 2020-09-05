/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:18:39 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/20 16:05:34 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	swap_list(t_list **prevnext, t_list *last)
{
	t_list	*swap;

	swap = *prevnext;
	*prevnext = last->next;
	swap->next = last->next->next;
	(*prevnext)->next = swap;
}

void	list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*last;
	t_list	*prev;

	prev = NULL;
	last = *begin_list;
	while (last && last->next)
	{
		if (cmp(last->data, last->next->data) > 0)
		{
			if (prev == NULL)
				swap_list(begin_list, last);
			else
				swap_list(&(prev->next), last);
			last = *begin_list;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next;
		}
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
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
	list_sort(begin_list1, cmp);
}
