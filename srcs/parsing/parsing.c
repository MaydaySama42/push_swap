/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 05:37:02 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/14 07:56:13 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sorting.h"
#include <limits.h>
#include <stdlib.h>

static int	check(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = ft_atol(str);
	if (!ft_str_isdigit(str) || ft_str_isempty(str))
		return (-1);
	if (nb > INT_MAX || nb < INT_MIN)
		return (-1);
	return (0);
}

static int	check_tab(char *str)
{
	char	**tab;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	tab = ft_strsplit(str, "\n\t ");
	if (tab[i] == NULL)
		return (-1);
	while (tab[i])
	{
		if ((ret = check(tab[i])) == -1)
			break ;
		free(tab[i]);
		i++;
	}
	free(tab);
	return (ret);
}

int			parse_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (i > ac - 1)
		return (-1);
	while (i < ac)
	{
		if (ft_istab(av[i]))
		{
			if (check_tab(av[i]) == -1)
				return (-1);
		}
		else if (check(av[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int			parse_list(t_list *pile)
{
	t_list	*tmp;
	t_list	*begin;

	tmp = pile;
	begin = pile;
	while (begin)
	{
		tmp = begin;
		while (tmp)
		{
			if (tmp->nb == begin->nb && tmp != begin)
				return (-1);
			tmp = tmp->next;
		}
		begin = begin->next;
	}
	return (0);
}
