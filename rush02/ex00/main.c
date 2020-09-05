/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:47:42 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/23 20:52:45 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ret_and_free(t_line *line, t_dict *dict, int ret)
{
	t_line	*current;
	t_dict	*current_d;

	while (line)
	{
		current = line;
		line = line->next;
		free(current->line);
		free(current);
	}
	while (dict)
	{
		current_d = dict;
		dict = dict->next;
		free(current_d);
	}
	return (ret);
}

int		process(char *dict_path, char *entry)
{
	int		result;
	t_line	*file_lines;
	t_dict	*dict;

	dict = NULL;
	file_lines = NULL;
	if (!load_file(dict_path, &file_lines, 0))
		return (ret_and_free(file_lines, dict, 0));
	if (!make_dict(file_lines, &dict, 0, 0) || !check_dict(dict) || !dict)
		return (ret_and_free(file_lines, dict, 0));
	result = 1;
	dict->action = ft_check_output;
	convert(entry, dict, &result);
	if (!result)
		return (ret_and_free(file_lines, dict, 0));
	dict->action = ft_putstr_s;
	convert(entry, dict, &result);
	if (result && (entry = get_block_name("0", 1, 1, dict)))
		ft_putstr(entry);
	else if (result)
		return (ret_and_free(file_lines, dict, 0));
	return (ret_and_free(file_lines, dict, 1));
}

int		main(int argc, char **argv)
{
	char	*entry;
	char	*dict_path;

	dict_path = "numbers.dict";
	if (argc > 1 && argc <= 3)
	{
		entry = argv[1];
		if (argc == 3)
		{
			entry = argv[2];
			dict_path = argv[1];
		}
		if (!(entry = is_valid_entry(entry)))
			return (error());
		if (!(process(dict_path, entry)))
			return (dict_error());
		write(1, "\n", 1);
	}
	else
		return (error());
	return (0);
}
