/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 07:58:03 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/20 07:32:40 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_list		*get_next_element(t_list *pile, t_list *elem)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp == elem)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (pile);
	return (tmp->next);
}

void		insertion_sort(t_list **pile_a, t_list **pile_b)
{
	t_list	*last;
	t_list	*copy;
	t_list	*tmp;

	last = NULL;
	copy = NULL;
	while (42)
	{
		if (check_is_sort(*pile_a, *pile_b) == 0)
			break ;
		last = get_min_value(*pile_a, copy);
		if (!copy)
		{
			move_elem_rotate(pile_a, last);
			list_push_front(&copy, create_elem(last->nb));
		}
		else
		{
			move_elem_rotate(pile_a, last);
			pb(pile_b, pile_a);
			tmp = get_elem_by_value(*pile_a, copy->nb);
			move_elem_rotate(pile_a, get_next_element(*pile_a, tmp));
			pa(pile_a, pile_b);
			sa(pile_a);
			list_push_front(&copy, create_elem(last->nb));
		}
	}
}
