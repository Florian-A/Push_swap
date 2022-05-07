/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_sb1(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 0);
	sb(&push_swap);
	if (!(push_swap.stack[1] == NULL))
	{
		cleaning(&push_swap);
		return (-1);
	}
	cleaning(&push_swap);
	return (0);
}

static int	test_sb2(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 1);
	sb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	cleaning(&push_swap);
	return (0);
}

static int	test_sb3(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 2);
	sb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 1
			&& ((t_block *)push_swap.stack[1]->next->content)->nb == 0))
	{
		cleaning(&push_swap);
		return (-1);
	}
	cleaning(&push_swap);
	return (0);
}

static int	test_sb4(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 3);
	sb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->next->previous->content)->nb == 1
			&& ((t_block *)push_swap.stack[1]
				->next->next->previous->content)->nb == 0
			&& ((t_block *)push_swap.stack[1]
				->next->next->content)->nb == 2))
	{
		cleaning(&push_swap);
		return (-1);
	}
	cleaning(&push_swap);
	return (0);
}

int	test_sb(void)
{
	if (test_sb1() == -1)
		return (-1);
	if (test_sb2() == -1)
		return (-1);
	if (test_sb3() == -1)
		return (-1);
	if (test_sb4() == -1)
		return (-1);
	return (0);
}
