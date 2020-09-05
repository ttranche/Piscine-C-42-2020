/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:49:33 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/21 15:49:09 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	void *left;
	void *right;

	if (root && (left = btree_search_item(root->left, data_ref, cmpf)))
		return (left);
	if (root && cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (root && (right = btree_search_item(root->right, data_ref, cmpf)))
		return (right);
	return (NULL);
}
