/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:47:21 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/20 06:54:16 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "checker.h"
#include "parsing.h"
#include "error.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#define SPEED_LOW	1000000000
#define SPEED_MED	100000000
#define SPEED_HIGH	30000000

int		main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	char	*line;
	int		size;
	int		coup;

	coup = 0;
	line = NULL;
	if (parse_args(ac, av) == -1)
		return (usage());
	pile_a = new_list(ac, av);
	pile_b = NULL;
	if (parse_list(pile_a) == -1)
		return (usage());
	size = get_list_size(pile_a);
	while (42)
	{
		get_next_line(0, &line);
		//system("clear");
		//print_two_list(pile_a, pile_b, size);
		ft_printfast("\x1b[36mstroke number: %d\x1b[0m\n", coup);
		for (int i = 0;i < SPEED_LOW;i++)
			;
		if (interpret_action(line, &pile_a, &pile_b) == 1)
			break ;
		coup++;
		//system("clear");
		print_two_list(pile_a, pile_b, size);
		ft_printfast("\x1b[36mstroke number: %d\x1b[0m\n", coup);
	}
	free(line);
	return (0);
}
