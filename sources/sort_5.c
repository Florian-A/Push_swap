/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5(t_push_swap *push_swap)
{
	if (!is_sorted(push_swap->stack[0]))
	{
		push_index(push_swap, 0);
		push_index(push_swap, 1);
		sort_3(push_swap);
		if (((t_block *)push_swap->stack[1]->content)->index == 0)
			sb(push_swap);
		pa(push_swap);
		pa(push_swap);
	}
}
