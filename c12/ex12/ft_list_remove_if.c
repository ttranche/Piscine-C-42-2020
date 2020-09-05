/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:03:08 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/20 10:51:34 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *))
{
	t_list *prev;
	t_list *aftr;
	t_list *curr;

	prev = NULL;
	aftr = *begin_list;
	while (aftr)
	{
		if (cmp(aftr->data, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = aftr->next;
			else
				prev->next = aftr->next;
			curr = aftr;
			aftr = aftr->next;
			free_fct(curr->data);
			free(curr);
		}
		else
		{
			prev = aftr;
			aftr = prev->next;
		}
	}
}
