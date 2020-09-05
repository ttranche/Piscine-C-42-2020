/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:13:53 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/20 15:55:22 by ttranche         ###   ########.fr       */
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *first;

	if (!(first = ft_create_elem(data)))
		return ;
	first->next = *begin_list;
	*begin_list = first;
	list_sort(begin_list, cmp);
}
