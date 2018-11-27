/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:40:36 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/14 08:22:03 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"
#include <stdlib.h>

void	push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	list_push_front(dest, create_elem((*src)->nb));
	free((*src));
	(*src) = tmp;
}

void	pa(t_list **dest, t_list **src)
{
	push(dest, src);
	ft_putendl("pa");
}

void	pb(t_list **dest, t_list **src)
{
	push(dest, src);
	ft_putendl("pb");
}
