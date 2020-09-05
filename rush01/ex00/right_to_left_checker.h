/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_to_left_checker.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:14:17 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:15:46 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RIGHT_TO_LEFT_CHECKER_H
# define RIGHT_TO_LEFT_CHECKER_H

# include <stdlib.h>

int		get_maximum_visible_right(int *row, int *ava, int tabsize);
int		get_minimum_visible_right(int *row, int *ava, int tabsize);
int		is_valid_to_right(int side, int *row, int *ava, int tabsize);

#endif
