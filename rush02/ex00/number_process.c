/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:54:01 by tmoragli          #+#    #+#             */
/*   Updated: 2020/08/23 18:44:52 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	convert(char *value, t_dict *dictionary, int *first)
{
	int		num_len;
	char	*scale_name;
	int		block_size;
	int		did;

	num_len = ft_strlen(value);
	block_size = num_len % 3;
	if (block_size == 0)
		block_size = 3;
	did = write_block(value, block_size, dictionary, first);
	if (num_len <= 0)
		return ;
	if (num_len > 3 && did)
		dictionary->action(first, (scale_name = get_block_name(
			"1", num_len - block_size + 1, 1, dictionary)));
	value += block_size;
	if (*value)
		convert(value, dictionary, first);
}
