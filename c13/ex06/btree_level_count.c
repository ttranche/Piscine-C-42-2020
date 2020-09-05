/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:12:17 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/21 14:53:08 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		max(int a, int b)
{
	return (a < b ? b : a);
}

int		btree_level_count(t_btree *root)
{
	int max_l;
	int max_r;

	if (!root)
		return (0);
	max_l = btree_level_count(root->left);
	max_r = btree_level_count(root->right);
	return (max(max_l, max_r) + 1);
}
