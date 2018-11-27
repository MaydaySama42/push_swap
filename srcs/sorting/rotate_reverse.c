/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:03:05 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/14 09:03:05 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"
#include <stdlib.h>

void	rotate_reverse(t_list **pile)
{
	t_list	*save;
	t_list	*tmp;
	t_list	*prev;

	save = (*pile);
	tmp = *pile;
	prev = tmp;
	if (!tmp || !(tmp->next))
		return ;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	(*pile) = tmp;
	(*pile)->next = save;
	prev->next = NULL;
}

void	rra(t_list **pile)
{
	rotate_reverse(pile);
	ft_putendl("rra");
}

void	rrb(t_list **pile)
{
	rotate_reverse(pile);
	ft_putendl("rrb");
}

void	rrr(t_list **pile_a, t_list **pile_b)
{
	rotate_reverse(pile_a);
	rotate_reverse(pile_b);
	ft_putendl("rrr");
}
