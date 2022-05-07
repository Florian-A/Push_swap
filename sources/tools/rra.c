/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:50:13 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_push_swap *push_swap)
{
	t_list	*lst1;

	if (push_swap->stack[0] != NULL && push_swap->stack[0]->next != NULL)
	{
		lst1 = ft_lstlast(push_swap->stack[0]);
		ft_lstlast(push_swap->stack[0])->previous->next = NULL;
		lst1->previous = NULL;
		ft_lstadd_front(&push_swap->stack[0], lst1);
		write(1, "rra\n", 4);
	}
}
