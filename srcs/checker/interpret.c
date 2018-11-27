/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 06:58:20 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/18 09:38:05 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "sorting.h"
#include "libft.h"

static void	interpret_swap(char *line, t_list **pile_a, t_list **pile_b)
{
	if (line[1] == 'a')
		swap(pile_a);
	if (line[1] == 'b')
		swap(pile_b);
	if (line[1] == 's')
	{
		swap(pile_a);
		swap(pile_b);
	}
}

static void	interpret_rotate(char *line, t_list **pile_a, t_list **pile_b)
{
	if (line[1] == 'a')
		rotate(pile_a);
	if (line[1] == 'b')
		rotate(pile_b);
	if (line[1] == 'r')
	{
		rotate(pile_a);
		rotate(pile_b);
	}
}

static void	interpret_rotate_reverse(char *line, t_list **pile_a,
	t_list **pile_b)
{
	if (line[2] == 'a')
		rotate_reverse(pile_a);
	if (line[2] == 'b')
		rotate_reverse(pile_b);
	if (line[2] == 'r')
	{
		rotate_reverse(pile_a);
		rotate_reverse(pile_b);
	}
}

static void	interpret_push(char *line, t_list **pile_a, t_list **pile_b)
{
	if (line[1] == 'a')
		push(pile_a, pile_b);
	if (line[1] == 'b')
		push(pile_b, pile_a);
}

int			interpret_action(char *line, t_list **pile_a, t_list **pile_b)
{
	if (line[0] == 's')
		interpret_swap(line, pile_a, pile_b);
	if (line[0] == 'r')
	{
		if (line[1] == 'r' && line[2])
			interpret_rotate_reverse(line, pile_a, pile_b);
		else
			interpret_rotate(line, pile_a, pile_b);
	}
	if (line[0] == 'p')
		interpret_push(line, pile_a, pile_b);
	if (ft_strcmp(line, "OK") == 0 || ft_strcmp(line, "KO") == 0)
		return (1);
	return (0);
}
