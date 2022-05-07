/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_rb1(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 0);
	rb(&push_swap);
	if (!(push_swap.stack[1] == NULL))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rb2(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 1);
	rb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rb3(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 2);
	rb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 1
			&& ((t_block *)push_swap.stack[1]->next->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

static int	test_rb4(void)
{
	t_push_swap	push_swap;

	init_s_stack(&push_swap);
	auto_fill_stack(&push_swap, 1, 3);
	rb(&push_swap);
	if (!(((t_block *)push_swap.stack[1]->content)->nb == 1
			&& ((t_block *)push_swap.stack[1]->next->content)->nb == 2
			&& ((t_block *)push_swap.stack[1]->next->next->content)->nb == 0
		))
	{
		cleaning(&push_swap);
		return (-1);
	}
	return (0);
}

int	test_rb(void)
{
	if (test_rb1() == -1)
		return (-1);
	if (test_rb2() == -1)
		return (-1);
	if (test_rb3() == -1)
		return (-1);
	if (test_rb4() == -1)
		return (-1);
	return (0);
}
