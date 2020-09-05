/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:14:16 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/22 14:29:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>
#include <stdio.h>

t_btree	*data_create_elem(void *data)
{
	t_btree *elem;

	if (!(elem = malloc(sizeof(t_btree))))
		return (NULL);
	elem->item = data;
	elem->left = NULL;
	return (elem);
}

void	data_list_push_back(t_btree **begin_list, void *data)
{
	t_btree	*last;

	last = *begin_list;
	if (!last)
		*begin_list = data_create_elem(data);
	else
		while (last)
		{
			if (!(last->left))
			{
				last->left = data_create_elem(data);
				last = (0);
			}
			else
				last = last->left;
		}
}

int		btree_level_count2(t_btree *root)
{
	int max_l;
	int max_r;

	if (!root)
		return (0);
	max_l = btree_level_count2(root->left);
	max_r = btree_level_count2(root->right);
	return ((max_l > max_r ? max_l : max_r) + 1);
}

void	get_level_list(t_btree *root, int target, int current, t_btree **list)
{
	if (root && current == target)
	{
		data_list_push_back(list, root->item);
		return ;
	}
	if (root)
	{
		get_level_list(root->left, target, current + 1, list);
		get_level_list(root->right, target, current + 1, list);
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)
		(void *item, int current_level, int is_first_elem))
{
	int		current_level;
	int		max_level;
	t_btree	*level_list;
	int		first;

	max_level = btree_level_count2(root);
	current_level = 0;
	while (current_level < max_level)
	{
		first = 0;
		level_list = NULL;
		get_level_list(root, current_level, 0, &level_list);
		while (level_list)
		{
			applyf(level_list->item, current_level, first == 0);
			level_list = level_list->left;
			++first;
		}
		++current_level;
	}
}
