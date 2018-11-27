/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 02:27:31 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/19 03:57:56 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include <limits.h>
#include <time.h>
#include <stdlib.h>

int		usage(void)
{
	ft_printfast_fd(2, "Error\n");
	return (-1);
}

void	init_options(t_options *op)
{
	op->min = (long)INT_MIN - 1;
	op->max = (long)INT_MIN - 1;
}

int		main(int ac, char **av)
{
	t_options	op;

	init_options(&op);
	srand(time(NULL));
	if (parse_args(&op, ac, av) == ERROR)
		return (usage());
	if (op.min != (long)INT_MIN - 1 && op.max == (long)INT_MIN - 1)
		generate_random(op);
	else if (op.min != (long)INT_MIN - 1 && op.max != (long)INT_MIN - 1)
		generate_sorted(op);
	else
		return (usage());
	return (0);
}
