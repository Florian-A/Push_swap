/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_sa1(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 0);
	sa(&push_swap);
	if (!(push_swap.stack[0] == NULL))
	{
		cleaning(&push_swap);
		return (-1);
	}
	cleaning(&push_swap);
	return (0);
}

static int	test_sa2(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 1);
	sa(&push_swap);
	if (!(((t_block *)push_swap.stack[0]->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	cleaning(&push_swap);
	return (0);
}

static int	test_sa3(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 2);
	sa(&push_swap);
	if (!(((t_block *)push_swap.stack[0]->content)->nb == 1
			&& ((t_block *)push_swap.stack[0]->next->content)->nb == 0))
	{
		cleaning(&push_swap);
		return (-1);
	}
	cleaning(&push_swap);
	return (0);
}

static int	test_sa4(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 0, 3);
	sa(&push_swap);
	if (!(((t_block *)push_swap.stack[0]->next->previous->content)->nb == 1
			&& ((t_block *)push_swap.stack[0]
				->next->next->previous->content)->nb == 0
			&& ((t_block *)push_swap.stack[0]
				->next->next->content)->nb == 2))
	{
		cleaning(&push_swap);
		return (-1);
	}
	cleaning(&push_swap);
	return (0);
}

int	test_sa(void)
{
	if (test_sa1() == -1)
		return (-1);
	if (test_sa2() == -1)
		return (-1);
	if (test_sa3() == -1)
		return (-1);
	if (test_sa4() == -1)
		return (-1);
	return (0);
}
