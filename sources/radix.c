/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix(t_push_swap *push_swap)
{
	int	i;
	int	j;
	int	k;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstsize(push_swap->stack[0]);
	while (!is_sorted(push_swap->stack[0]))
	{
		j = 0;
		while (j++ < size_a)
		{
			if (((((t_block *)push_swap->stack[0]->content)->index >> i) &1))
				ra(push_swap);
			else
				pb(push_swap);
		}
		size_b = ft_lstsize(push_swap->stack[1]);
		k = 0;
		while (k++ < size_b)
			pa(push_swap);
		i++;
	}
}
