/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:10:15 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:11:42 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include <stdlib.h>
# include <unistd.h>

int		print_map(int **tab, int tabsize);
int		**malloc_the_grid(int tabsize);

#endif
