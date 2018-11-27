/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 05:34:21 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/14 07:48:25 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "libft.h"
#include <stdlib.h>

void	add_from_tab(t_list **list, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, "\n\t ");
	while (tab[i])
	{
		list_push_back(list, create_elem(ft_atoi(tab[i])));
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		get_list_size(t_list *list)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
