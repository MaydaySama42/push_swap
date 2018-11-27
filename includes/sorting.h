/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:41:04 by mdalil            #+#    #+#             */
/*   Updated: 2018/11/19 07:30:23 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# define SENS_GO_UP		1
# define SENS_GO_DOWN	2

typedef	struct		s_list
{
	int				nb;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

/*
**					list creation
*/
t_list				*new_list(int ac, char **av);
t_list				*create_elem(int nb);
void				list_push_front(t_list **list, t_list *elem);
void				list_push_back(t_list **list, t_list *elem);
void				add_from_tab(t_list **list, char *str);
/*
**					list utils
*/
int					get_list_size(t_list *list);
/*
**					pile display
*/
void				print_list(t_list *list);
void				print_two_list(t_list *pile_a, t_list *pile_b, int size);
/*
**					orders
*/
void				swap(t_list **pile);
void				push(t_list **dest, t_list **src);
void				rotate(t_list **pile);
void				rotate_reverse(t_list **pile);
/*
**					actions
*/
void				pa(t_list **dest, t_list **src);
void				pb(t_list **dest, t_list **src);
void				sa(t_list **pile);
void				sb(t_list **pile);
void				ss(t_list **pile_a, t_list **pile_b);
void				ra(t_list **pile);
void				rb(t_list **pile);
void				rr(t_list **pile_a, t_list **pile_b);
void				rra(t_list **pile);
void				rrb(t_list **pile);
void				rrr(t_list **pile_a, t_list **pile_b);
/*
**					sort
*/
void				insertion_sort(t_list **pile_a, t_list **pile_b);
void				selection_sort(t_list **pile_a, t_list **pile_b);
/*
**					sort utils
*/
int					check_is_sort(t_list *pile_a, t_list *pile_b);
t_list				*get_min_value(t_list *pile, t_list *copy);
int					get_direction(t_list *pile, t_list *min);
void				move_elem_rotate(t_list **pile, t_list *elem);
t_list				*get_elem_by_value(t_list *pile, int nb);

#endif
