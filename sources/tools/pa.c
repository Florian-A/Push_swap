
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:45:33 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_push_swap *push_swap)
{
	t_list	*lst1;
	t_list	*lst2;

	if (push_swap->stack[1] != NULL)
	{
		lst1 = push_swap->stack[1];
		lst2 = push_swap->stack[1]->next;
		push_swap->stack[1] = lst2;
		if (push_swap->stack[1] != NULL)
			push_swap->stack[1]->previous = NULL;
		lst1->next = NULL;
		if (push_swap->stack[0] == NULL)
			push_swap->stack[0] = lst1;
		else
			ft_lstadd_front(&push_swap->stack[0], lst1);
		write(1, "pa\n", 3);
	}
}
