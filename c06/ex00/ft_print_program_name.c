/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 09:21:07 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/11 20:36:41 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	char *name;

	(void)argc;
	name = argv[0];
	while (*name)
		write(1, name++, 1);
	write(1, "\n", 1);
	return (0);
}
