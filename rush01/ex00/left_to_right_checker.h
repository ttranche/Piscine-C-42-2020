/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_to_right_checker.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:12:14 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:13:43 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEFT_TO_RIGHT_CHECKER_H
# define LEFT_TO_RIGHT_CHECKER_H

# include <stdlib.h>

int		get_current_visible_left(int *row, int tabsize, int *biggest);
int		is_valid_to_left(int side, int *row, int *ava, int tabsize);

#endif
