/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:35:28 by mdalil            #+#    #+#             */
/*   Updated: 2018/12/20 05:02:39 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	little_sort(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (get_list_size(*pile_a) > 3)
	{
		tmp = get_max_value(*pile_a);
		move_elem_rotate(pile_a, tmp);
		pb(pile_b, pile_a);
		tmp = get_min_value(*pile_a);
		move_elem_rotate(pile_a, tmp);
		pb(pile_b, pile_a);
	}

	if ((*pile_a)->nb > (*pile_a)->next->nb)
		sa(pile_a);
	if (get_list_size(*pile_a) > 2)
	{
		if ((*pile_a)->next->nb > (*pile_a)->next->next->nb && (*pile_a)->next->next->nb > (*pile_a)->nb)
		{
			ra(pile_a);
			sa(pile_a);
		}	
	}
	tmp = get_min_value(*pile_a);
	move_elem_rotate(pile_a, tmp);
	if (*pile_b)
	{
		pa(pile_a, pile_b);
		pa(pile_a, pile_b);
		ra(pile_a);
	}
}
