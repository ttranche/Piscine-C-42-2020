/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:17:44 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:19:11 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROW_UTILS_H
# define ROW_UTILS_H

# include <stdlib.h>

int		*get_available_nums(int *row, int tabsize);
int		*rotate_col(int pos, int **tab, int tabsize);
int		check_dupe(int **tab, int pos, int value, int tabsize);

#endif
