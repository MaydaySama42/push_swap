/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 04:47:14 by mdalil            #+#    #+#             */
/*   Updated: 2018/12/19 20:36:38 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"
#include <stdlib.h>

void	selection_sort(t_list **pile_a, t_list **pile_b)
{
	t_list	*min;
	int		sens;

	sens = 0;
	while ((min = get_min_value(*pile_a)))
	{
		move_elem_rotate(pile_a, min);
		pb(pile_b, pile_a);
	}
	while (*pile_b)
		pa(pile_a, pile_b);
}
