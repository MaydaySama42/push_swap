/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_method.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 03:06:18 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/19 03:56:54 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include <time.h>
#include <stdlib.h>

static int	ft_abs(int nb)
{
	return (nb >= 0 ? nb : -nb);
}

void		check_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] == tab[j] && &tab[i] != &tab[j])
			{
				tab[i] = rand();
				j = 0;
				continue ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void		print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printfast("%d ", tab[i]);
		i++;
	}
	free(tab);
}

void		generate_random(t_options op)
{
	int	i;
	int	nb;
	int	*tab;

	i = 0;
	if (op.min <= 0)
	{
		ft_printfast("Error\n");
		return ;
	}
	if (!(tab = malloc(sizeof(int) * op.min)))
		return ;
	while (i < op.min)
	{
		nb = rand();
		nb = nb / 100000 > 0 ? nb / 100000 : nb;
		tab[i] = nb;
		check_tab(tab, op.min);
		i++;
	}
	print_tab(tab, op.min);
}

void		generate_sorted(t_options op)
{
	int	i;
	int	size;

	size = op.max - op.min;
	i = ft_abs(size);
	while (i >= 0)
	{
		ft_printfast("%d ", op.min);
		op.min += size > 0 ? 1 : -1;
		i--;
	}
}
