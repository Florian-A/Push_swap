/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void static	display_two_stack(t_list *lsta, t_list *lstb, int len);

void	show_stack(t_push_swap *push_swap)
{
	int		len;
	int		lst_lenb;
	t_list	*lsta;
	t_list	*lstb;

	len = ft_lstsize(push_swap->stack[0]);
	lst_lenb = ft_lstsize(push_swap->stack[1]);
	if (lst_lenb > len)
		len = lst_lenb;
	ft_printf("---------------------------------------------------\n");
	ft_printf("Stack A			| Stack B\n");
	ft_printf("---------------------------------------------------\n");
	lsta = push_swap->stack[0];
	lstb = push_swap->stack[1];
	display_two_stack(lsta, lstb, len);
	ft_printf("---------------------------------------------------\n");
}

void static	display_two_stack(t_list *lsta, t_list *lstb, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (lsta)
			ft_printf("i: %d n: %d		", ((t_block *)lsta->content)->index, \
				((t_block *)lsta->content)->nb);
		else
			ft_printf("i: null n: null		");
		if (lstb)
			ft_printf("| i: %d n: %d \n", ((t_block *)lstb->content)->index, \
				((t_block *)lstb->content)->nb);
		else
			ft_printf("| i: null n: null \n");
		if (lsta)
			lsta = lsta->next;
		if (lstb)
			lstb = lstb->next;
		i++;
	}
}
