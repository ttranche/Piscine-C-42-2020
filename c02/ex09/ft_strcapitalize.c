/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:27:13 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/06 16:24:59 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int was_space;

	i = 0;
	was_space = 1;
	while (str[i])
	{
		if (was_space && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (!was_space && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		was_space = !((str[i] >= 'a' && str[i] <= 'z') ||
					(str[i] >= 'A' && str[i] <= 'Z') ||
					(str[i] >= '0' && str[i] <= '9'));
		++i;
	}
	return (str);
}
