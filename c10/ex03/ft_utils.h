/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:47:55 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/14 10:55:11 by ttranche         ###   ########.fr       */
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

typedef struct	s_option
{
	int		read_bytes;
	char	buf[16];
	char	last[16];
	int		didstar;
	int		offset;
	int		file;
	int		temp;
	int		i;
	int		op;
	char	*exec;
	char	**paths;
	int		count;
	int		went;
}				t_option;

int				is_duplicate(char *buf, char *last, int read, int didstar);
void			ft_puterr(char *str);
int				print_err(char *binpath, char *filepath);
char			*ft_stradd(char *buf, char *add, int *bufsize, int addsize);
char			*createbuffer(int port, int *retsize);

#endif
