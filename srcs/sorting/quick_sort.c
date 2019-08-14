/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:02:59 by mdalil            #+#    #+#             */
/*   Updated: 2018/12/19 20:07:11 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int		create_index(t_list **index, t_list **pile_a)
{
	int		m;
	int		s;
	t_list	*tmp;

	m = 0;
	while (42)
	{
		if (get_list_size(*index) == get_list_size(*pile_a))
			break ;
		tmp = get_min_value_from_pile(*pile_a, *index);
		list_push_back(index, create_elem(tmp->nb));
	}
	tmp = *index;
	s = get_list_size(*index);
	if (s % 2)
		m = get_list_at(*index, (s / 2))->nb;
	else
		m = (get_list_at(*index, (s / 2) - 1)->nb + get_list_at(*index, (s / 2))->nb) / 2;
	return (m);
}