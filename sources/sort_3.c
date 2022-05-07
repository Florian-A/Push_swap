/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_lowerindex(t_push_swap *push_swap);

void	sort_3(t_push_swap *push_swap)
{
	int	indexes[4];

	indexes[0] = ((t_block *)push_swap->stack[0]->content)->index;
	indexes[1] = ((t_block *)push_swap->stack[0]->next->content)->index;
	indexes[2] = ((t_block *)push_swap->stack[0]->next->next->content)->index;
	indexes[3] = get_lowerindex(push_swap);
	if (indexes[0] == (indexes[3] + 0) && indexes[1] == (indexes[3] + 2))
	{
		sa(push_swap);
		ra(push_swap);
	}
	else if (indexes[0] == (indexes[3] + 1) && indexes[1] == (indexes[3] + 0))
		sa(push_swap);
	else if (indexes[0] == (indexes[3] + 2) && indexes[1] == (indexes[3] + 1))
	{
		sa(push_swap);
		rra(push_swap);
	}
	else if (indexes[0] == (indexes[3] + 2) && indexes[1] == (indexes[3] + 0))
	{
		rra(push_swap);
		rra(push_swap);
	}
	else if (indexes[2] == (indexes[3] + 0))
		rra(push_swap);
}

static int	get_lowerindex(t_push_swap *push_swap)
{
	int		lowerindex;
	t_list	*lst;

	lowerindex = -1;
	lst = push_swap->stack[0];
	while (lst)
	{
		if (lowerindex == -1 || ((t_block *)lst->content)->index < lowerindex)
			lowerindex = ((t_block *)lst->content)->index;
		lst = lst->next;
	}
	return (lowerindex);
}
