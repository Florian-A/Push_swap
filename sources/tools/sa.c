/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_push_swap *push_swap)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	if (push_swap->stack[0] != NULL && push_swap->stack[0]->next != NULL)
	{
		lst1 = push_swap->stack[0];
		lst2 = push_swap->stack[0]->next;
		lst3 = push_swap->stack[0]->next->next;
		push_swap->stack[0] = push_swap->stack[0]->next;
		push_swap->stack[0]->next = lst1;
		push_swap->stack[0]->next->next = lst3;
		push_swap->stack[0]->previous = NULL;
		push_swap->stack[0]->next->previous = lst2;
		if (push_swap->stack[0]->next->next != NULL)
			push_swap->stack[0]->next->next->previous = lst1;
		write(1, "sa\n", 3);
	}
}
