/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:37:14 by tmoragli          #+#    #+#             */
/*   Updated: 2020/08/23 20:54:58 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_line
{
	char			*line;
	int				size;
	struct s_line	*next;
}					t_line;

typedef struct		s_dict
{
	char			*number;
	char			*name;
	void			(*action)(int*, char*);
	struct s_dict	*next;
}					t_dict;

void				ft_check_output(int *result, char *str);
char				*is_valid_entry(char *orig);
int					dict_error();
int					error();
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcat(char *str, char c, int size);
void				ft_putstr_s(int *first, char *str);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_isspace(char c);
void				convert(char *value, t_dict *dictionary, int *first);
int					load_file(char *path, t_line **first, int size);
int					add_line(t_line **line, char *data);
int					make_dict(t_line *lines, t_dict **dict, char *str,
						char *dupe);
int					add_dict(t_dict **dict, char *number, char *name);
int					check_dupe(t_dict *dict, char *val);
int					check_dict(t_dict *dict);
char				*get_block_name(char *begin, int size,
						int cmpsize, t_dict *dictionary);
int					write_block(char *begin, int size,
						t_dict *dict, int *first);

#endif
