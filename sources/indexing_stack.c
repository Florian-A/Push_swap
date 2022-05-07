/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing_stack(t_push_swap *push_swap)
{
	int		i;
	t_list	*lst1;
	t_list	*lst2;

	lst1 = push_swap->stack[0];
	lst2 = lst1;
	while (lst1)
	{
		i = 0;
		while (lst2)
		{
			if (((t_block *)lst1->content)->nb > ((t_block *)lst2->content)->nb)
				i++;
			lst2 = lst2->next;
		}
		((t_block *)lst1->content)->index = i;
		lst1 = lst1->next;
		lst2 = ft_lstfirst(lst1);
	}
}
