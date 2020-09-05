/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:47:55 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/15 19:26:09 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_stradd(char *buf, char *add, int *bufsize, int addsize);
void	ft_puterr(char *str);
void	ft_putstr(char *str);
void	print_err(char *binpath, char *filepath);
int		miniatoi(char *str, char *exec);

#endif
