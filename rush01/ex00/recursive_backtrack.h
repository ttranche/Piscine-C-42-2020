/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_backtrack.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:16:36 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 17:17:26 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSIVE_BACKTRACK_H
# define RECURSIVE_BACKTRACK_H

# include <stdlib.h>

int		check(int **sidecheck, int **tab, int pos, int tabsize);
int		**resolve(int **sidecheck, int **tab, int pos, int tabsize);

#endif
