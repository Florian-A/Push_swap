/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_rra1(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 0);
	rra(&push_swap);
	if (!(push_swap.stack[0] == NULL))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rra2(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 1);
	rra(&push_swap);
	if (!(((t_block *)push_swap.stack[0]->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rra3(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 2);
	rra(&push_swap);
	if (!(((t_block *)push_swap.stack[0]->content)->nb == 1
			&& ((t_block *)push_swap.stack[0]->next->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rra4(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 3);
	rra(&push_swap);
	if (!(((t_block *)push_swap.stack[0]->content)->nb == 2
			&& ((t_block *)push_swap.stack[0]->next->content)->nb == 0
			&& ((t_block *)push_swap.stack[0]->next->next->content)->nb == 1
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

int	test_rra(void)
{
	if (test_rra1() == -1)
		return (-1);
	if (test_rra2() == -1)
		return (-1);
	if (test_rra3() == -1)
		return (-1);
	if (test_rra4() == -1)
		return (-1);
	return (0);
}
