/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:40:25 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/19 07:29:55 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"

void	swap(t_list **pile)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = *pile;
	b = a ? (*pile)->next : 0;
	if (!a || !b)
		return ;
	*pile = b;
	tmp = b->next;
	(*pile)->next = a;
	(*pile)->next->next = tmp;
}

void	sa(t_list **pile)
{
	swap(pile);
	ft_putendl("sa");
}

void	sb(t_list **pile)
{
	swap(pile);
	ft_putendl("sb");
}

void	ss(t_list **pile_a, t_list **pile_b)
{
	swap(pile_a);
	swap(pile_b);
	ft_putendl("ss");
}