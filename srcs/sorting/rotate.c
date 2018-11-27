/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:40:34 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/14 08:09:38 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"
#include <stdlib.h>

void	rotate(t_list **pile)
{
	t_list	*save;
	t_list	*tmp;

	save = *pile;
	tmp = *pile;
	if (!tmp || !(tmp->next))
		return ;
	while (tmp->next)
		tmp = tmp->next;
	(*pile) = (*pile)->next;
	tmp->next = save;
	if (tmp->next)
		tmp->next->next = NULL;
}

void	ra(t_list **pile)
{
	rotate(pile);
	ft_putendl("ra");
}

void	rb(t_list **pile)
{
	rotate(pile);
	ft_putendl("rb");
}

void	rr(t_list **pile_a, t_list **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	ft_putendl("rr");
}
