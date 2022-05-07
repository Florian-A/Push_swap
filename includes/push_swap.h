/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_push_swap {
	t_list	*stack[2];
}	t_push_swap;

typedef struct s_block {
	int		index;
	int		nb;
}	t_block;

// Tools for manipulating the linked list and initialization / cleaning.
void	sa(t_push_swap *push_swap);
void	sb(t_push_swap *push_swap);
void	pa(t_push_swap *push_swap);
void	pb(t_push_swap *push_swap);
void	ra(t_push_swap *push_swap);
void	rb(t_push_swap *push_swap);
void	rra(t_push_swap *push_swap);
void	rrb(t_push_swap *push_swap);
void	ss(t_push_swap *push_swap);
void	rr(t_push_swap *push_swap);
void	rrr(t_push_swap *push_swap);
void	cleaning(t_push_swap *push_swap);
void	init_s_stack(t_push_swap *push_swap);
int		auto_fill_stack(t_push_swap *push_swap, int n, int len);
int		fill_stack(t_push_swap *push_swap, char **argv);

// Core and sorting algorithm.
void	show_stack(t_push_swap *push_swap);
void	indexing_stack(t_push_swap *push_swap);
void	push_index(t_push_swap *push_swap, int index_nb);
int		is_sorted(t_list *lst);
void	radix(t_push_swap *push_swap);
void	sort_2(t_push_swap *push_swap);
void	sort_3(t_push_swap *push_swap);
void	sort_4(t_push_swap *push_swap);
void	sort_5(t_push_swap *push_swap);

#endif