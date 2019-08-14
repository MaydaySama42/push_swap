/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 07:21:05 by mdalil            #+#    #+#             */
/*   Updated: 2018/12/19 20:37:00 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"
#include "parsing.h"
#include "error.h"
#include "libft.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (parse_args(ac, av) == -1)
		return (usage());
	pile_a = new_list(ac, av);
	pile_b = NULL;
	if (parse_list(pile_a) == -1)
		return (usage());
	little_sort(&pile_a, &pile_b);
	ft_printfast("OK\n");
	return (0);
}
