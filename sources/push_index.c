/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_index(t_push_swap *push_swap, int index_nb);

void	push_index(t_push_swap *push_swap, int index_nb)
{
	int	i;
	int	pos_index;
	int	lst_size;

	i = 0;
	pos_index = get_index(push_swap, index_nb);
	lst_size = ft_lstsize(push_swap->stack[0]);
	if (pos_index == 0)
		pb(push_swap);
	else if (pos_index == lst_size -1)
	{
		rra(push_swap);
		pb(push_swap);
	}
	else
	{
		while (i++ < pos_index)
			ra(push_swap);
		pb(push_swap);
	}
}

static int	get_index(t_push_swap *push_swap, int index_nb)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = push_swap->stack[0];
	while (lst)
	{
		if (((t_block *)lst->content)->index == index_nb)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}
