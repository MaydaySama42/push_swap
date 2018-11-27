/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:47:34 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/18 00:22:40 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "checker.h"
#include "libft.h"
#include <stdlib.h>

t_list	*create_elem(int nb)
{
	t_list	*elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->nb = nb;
	elem->next = NULL;
	return (elem);
}

void	list_push_back(t_list **list, t_list *elem)
{
	t_list	*tmp;

	tmp = *list;
	if (!tmp)
	{
		*list = elem;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}

void	list_push_front(t_list **list, t_list *elem)
{
	t_list	*tmp;

	tmp = *list;
	*list = elem;
	(*list)->next = tmp;
}

t_list	*new_list(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 1;
	list = NULL;
	while (i < ac)
	{
		if (ft_istab(av[i]))
			add_from_tab(&list, av[i]);
		else
			list_push_back(&list, create_elem(ft_atoi(av[i])));
		i++;
	}
	return (list);
}

void	print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_printfast("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}

void	print_two_list(t_list *pile_a, t_list *pile_b, int size)
{
	int		size_a;
	int		size_b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = pile_a;
	tmp_b = pile_b;
	size_a = get_list_size(pile_a);
	size_b = get_list_size(pile_b);
	ft_printfast("\x1b[33m.---------------------------.\x1b[0m\n");
	while (size > 0)
	{
		if (size <= size_a)
		{
			ft_printfast("\x1b[33m|\x1b[0m\x1b[31m%12d\x1b[0m\x1b[33m|\x1b[0m ", tmp_a->nb);
			tmp_a = tmp_a->next;
		}
		else
			ft_printfast("\x1b[33m|\x1b[0m%12s\x1b[33m|\x1b[0m ", "");
		if (size <= size_b)
		{
			ft_printfast("\x1b[33m|\x1b[0m\x1b[35m%-12d\x1b[0m\x1b[33m|\x1b[0m ", tmp_b->nb);
			tmp_b = tmp_b->next;
		}
		else
			ft_printfast("\x1b[33m|\x1b[0m%12s\x1b[33m|\x1b[0m ", "");
		ft_printfast("\n");
		size--;
	}
	ft_printfast("\x1b[33m.---------------------------.\x1b[0m\n");
}
