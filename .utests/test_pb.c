/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_pb1(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 3);
	pb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 0
			&& ((t_block *)push_swap.stack[0]->content)->nb == 1
			&& ((t_block *)push_swap.stack[0]->next->content)->nb == 2))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_pb2(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 4);
	auto_fill_stack(&push_swap, 0, 1);
	pb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 0
			&& ((t_block *)push_swap.stack[1]->next->content)->nb == 0
			&& ((t_block *)push_swap.stack[1]->next->next->content)->nb == 1
			&& push_swap.stack[0] == NULL))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_pb3(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	pb(&push_swap);
	if (!(push_swap.stack[0] == NULL && push_swap.stack[1] == NULL))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_pb4(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 3);
	pb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 0
			&& ((t_block *)push_swap.stack[1]->next->content)->nb == 1
			&& ((t_block *)push_swap.stack[1]->next->next->content)->nb == 2))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

int	test_pb(void)
{
	if (test_pb1() == -1)
		return (-1);
	if (test_pb2() == -1)
		return (-1);
	if (test_pb3() == -1)
		return (-1);
	if (test_pb4() == -1)
		return (-1);
	return (0);
}
