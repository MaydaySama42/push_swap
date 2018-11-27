/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 02:29:22 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/19 03:57:03 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include <limits.h>

static int	check_number(char *str, t_options *op)
{
	long	nb;

	nb = ft_atol(str);
	if (nb < INT_MIN && nb > INT_MAX)
		return (ERROR);
	if (op->min == (long)INT_MIN - 1)
		op->min = nb;
	else if (op->max == (long)INT_MIN - 1)
		op->max = nb;
	else
		return (ERROR);
	return (0);
}

int			parse_args(t_options *op, int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (check_number(av[i], op) == ERROR)
			return (ERROR);
		i++;
	}
	return (0);
}
