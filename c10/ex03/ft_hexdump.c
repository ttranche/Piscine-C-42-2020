/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:53:28 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/16 15:28:32 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_mem.h"

void	subbytes(t_option *o)
{
	while (o->read_bytes < 16 && o->i < o->count)
	{
		if ((o->file = itopen(&(o->file), o->paths[o->i++])) <= 0)
		{
			print_err(o->exec, o->paths[o->i - 1]);
			continue ;
		}
		while (o->read_bytes < 16 &&
				(o->temp = read(o->file, o->buf + o->read_bytes, 1)))
			if (o->temp > 0)
				o->read_bytes += o->temp;
			else if (print_err(o->exec, o->paths[o->i - 1]))
			{
				if (o->i == o->count)
					++o->i;
				break ;
			}
	}
	if ((o->didstar = is_duplicate(o->buf, o->last,
		o->read_bytes, o->didstar)) && o->didstar == 1)
		write(1, "*\n", 2);
	else if (o->didstar == 0)
		ft_print_line(o->buf, o->read_bytes, o->offset, o->op);
	o->offset += o->read_bytes;
}

int		output_port(t_option *o)
{
	while (o->i < o->count && itopen(&(o->file), o->paths[o->i++]) <= 0)
		print_err(o->exec, o->paths[o->i - 1]);
	while ((o->read_bytes = read(o->file, o->buf, 16)) || o->i < o->count)
		if (++o->went && o->read_bytes <= 0)
		{
			if (o->i > o->count)
				break ;
			if (o->file > 0 && o->read_bytes == -1)
				print_err(o->exec, o->paths[o->i - 1]);
			if (o->i == o->count && (--o->went || 1))
				break ;
			while (o->i < o->count && itopen(&(o->file), o->paths[o->i++]) <= 0)
				print_err(o->exec, o->paths[o->i - 1]);
		}
		else
			subbytes(o);
	if (o->offset && ft_print_addr(o->offset, 0, o->op))
		write(1, "\n", 1);
	if (close(o->file) && !o->offset && !o->went)
		print_err(o->exec, o->paths[o->i - 1]);
	return (1);
}

int		output_stdin(t_option *o)
{
	int		i;
	char	*buffer;
	int		size;

	i = 0;
	o->file = STDIN_FILENO;
	if (!(buffer = createbuffer(o->file, &size)))
		return (0);
	while (i < size / 16)
	{
		if ((o->didstar = is_duplicate(buffer + (i * 16),
			o->last, 16, o->didstar)) && o->didstar == 1)
			write(1, "*\n", 2);
		else if (o->didstar == 0)
			ft_print_line(buffer + (i * 16), 16, i * 16, o->op);
		o->offset += o->read_bytes;
		++i;
	}
	if (size % 16 > 0)
		ft_print_line(buffer + (i * 16), size % 16, i * 16, o->op);
	if ((o->offset > 0 || size > 0) && ft_print_addr(size, 0, o->op))
		write(1, "\n", 1);
	free(buffer);
	return (1);
}

void	initparams(t_option *options, int argc, char **argv, int i)
{
	options->read_bytes = 0;
	options->offset = 0;
	options->i = 0;
	options->count = argc - i;
	options->paths = argv + i;
	options->exec = argv[0];
	options->didstar = 1;
	options->file = 0;
	options->went = 0;
}

int		main(int argc, char **argv)
{
	int			i;
	t_option	*options;

	options = malloc(sizeof(t_option));
	options->op = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] != 0)
	{
		while (*(argv[i]))
		{
			if (*(argv[i]) == 'C')
				options->op = 1;
			++(argv[i]);
		}
		++i;
	}
	initparams(options, argc, argv, i);
	if (options->count == 0)
		output_stdin(options);
	else
		output_port(options);
	return (0);
}
