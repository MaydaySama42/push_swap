/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 04:41:59 by mdalil            #+#    #+#             */
/*   Updated: 2018/12/19 20:29:27 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

t_list		*get_min_value(t_list *pile)
{
	t_list	*tmp;
	t_list	*ret;
	int		min_value;

	if (!(tmp = pile))
		return (NULL);
	ret = NULL;
	min_value = INT_MAX;
	while (tmp)
	{
		if (tmp->nb < min_value)
		{
			min_value = tmp->nb;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_list		*get_max_value(t_list *pile)
{
	t_list	*tmp;
	t_list	*ret;
	int		max_value;

	if (!(tmp = pile))
		return (NULL);
	ret = NULL;
	max_value = INT_MIN;
	while (tmp)
	{
		if (tmp->nb > max_value)
		{
			max_value = tmp->nb;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

int		get_direction(t_list *pile, t_list *min)
{
	t_list	*tmp;
	int		i;
	int		size;

	i = 0;
	size = get_list_size(pile);
	tmp = pile;
	while (tmp)
	{
		if (tmp == min)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i <= size / 2)
		return (SENS_GO_UP);
	else
		return (SENS_GO_DOWN);
	return (0);
}

void	move_elem_rotate(t_list **pile, t_list *elem)
{
	int	sens;

	sens = get_direction(*pile, elem);
	while (*pile != elem)
	{
		if (sens == SENS_GO_UP)
			ra(pile);
		else if (sens == SENS_GO_DOWN)
			rra(pile);
	}
}

int		check_is_sort(t_list *pile_a, t_list *pile_b)
{
	t_list	*tmp;
	int		value;

	tmp = pile_a;
	value = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < value)
			return (-1);
		value = tmp->nb;
		tmp = tmp->next;
	}
	if (pile_b && get_list_size(pile_b) != 0)
		return (-1);
	return (0);
}
