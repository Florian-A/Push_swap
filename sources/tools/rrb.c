
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:45:33 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrb(t_push_swap *push_swap)
{
	t_list	*lst1;

	if (push_swap->stack[1] != NULL && push_swap->stack[1]->next != NULL)
	{
		lst1 = ft_lstlast(push_swap->stack[1]);
		ft_lstlast(push_swap->stack[1])->previous->next = NULL;
		lst1->previous = NULL;
		ft_lstadd_front(&push_swap->stack[1], lst1);
		write(1, "rra\n", 4);
	}
}
