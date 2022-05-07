/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_rrb1(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 0);
	rrb(&push_swap);
	if (!(push_swap.stack[1] == NULL))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rrb2(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 1);
	rrb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rrb3(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 2);
	rrb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 1
			&& ((t_block *)push_swap.stack[1]->next->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rrb4(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 3);
	rrb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 2
			&& ((t_block *)push_swap.stack[1]->next->content)->nb == 0
			&& ((t_block *)push_swap.stack[1]->next->next->content)->nb == 1
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

int	test_rrb(void)
{
	if (test_rrb1() == -1)
		return (-1);
	if (test_rrb2() == -1)
		return (-1);
	if (test_rrb3() == -1)
		return (-1);
	if (test_rrb4() == -1)
		return (-1);
	return (0);
}
