/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:46:15 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/20 10:46:06 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_swap_list(t_list **prevnext, t_list *last)
{
	t_list	*swap;

	swap = *prevnext;
	*prevnext = last->next;
	swap->next = last->next->next;
	(*prevnext)->next = swap;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
				ft_swap_list(begin_list, last);
			else
				ft_swap_list(&(prev->next), last);
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
