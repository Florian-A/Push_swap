
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_fill_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:45:33 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	auto_fill_stack(t_push_swap *push_swap, int n, int len)
{
	int		i;
	t_block	*new_block;

	i = 0;
	while (i < len)
	{
		new_block = ft_calloc(sizeof(t_block), 1);
		if (!new_block)
			return (0);
		new_block->nb = i;
		if (i == 0)
		{
			push_swap->stack[n] = ft_lstnew(new_block);
			if (!push_swap->stack[n])
				return (0);
		}
		else
			ft_lstadd_back(&push_swap->stack[n], ft_lstnew(new_block));
		if (!push_swap->stack[n])
			return (0);
		i++;
	}
	return (1);
}
