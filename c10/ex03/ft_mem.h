/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:47:55 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/14 10:17:13 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_print_addr(int offset, int pos, int op);
void	ft_print_hex(unsigned char c);
void	ft_print_text(char *data, unsigned int size);
void	ft_print_line(void *addr, unsigned int size, int offset, int op);
int		itopen(int *file, char *path);

#endif
