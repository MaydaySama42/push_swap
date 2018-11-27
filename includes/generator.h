/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 02:27:42 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/19 03:58:00 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_H
# define GENERATOR_H

# define OPTIONS		"RANDOM:INC:DEC"
# define RANDOM			1
# define INC			2
# define DEC			4

# define ERROR			-1
# define NOT_AN_OPTION	-2

typedef struct	s_options
{
	long		min;
	long		max;
}				t_options;

int 			parse_args(t_options *op, int ac, char **av);
void			generate_random(t_options op);
void			generate_sorted(t_options op);

#endif