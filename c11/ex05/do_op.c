/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:04:19 by ttranche          #+#    #+#             */
/*   Updated: 2020/08/17 12:39:51 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		do_op(int num1, int num2, char *op)
{
	if (op[1] != 0)
		return (0);
	else if (*op == '+')
		return (num1 + num2);
	else if (*op == '-')
		return (num1 - num2);
	else if (*op == '/')
		return (num1 / num2);
	else if (*op == '*')
		return (num1 * num2);
	else if (*op == '%')
		return (num1 % num2);
	return (0);
}

void	ft_putnbr(int nb)
{
	long lnb;
	char temp;

	lnb = nb;
	if (lnb < 0)
	{
		lnb *= -1;
		write(1, "-", 1);
	}
	if (lnb > 9)
		ft_putnbr(lnb / 10);
	temp = '0' + (char)(lnb % 10);
	write(1, &temp, 1);
}

int		ft_atoi(char *str)
{
	long	ret;
	int		sign;

	sign = 1;
	ret = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		++str;
	while (*str == '+' || *str == '-')
	{
		sign *= *str == '-' ? -1 : 1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + *str - '0';
		++str;
	}
	return ((int)(ret * sign));
}

int		main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	op;

	if (argc != 4)
		return (0);
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	op = argv[2][0];
	if (argv[2][1] == 0 && op == '/' && num2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (argv[2][1] == 0 && op == '%' && num2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_putnbr(do_op(num1, num2, argv[2]));
	write(1, "\n", 1);
	return (0);
}
