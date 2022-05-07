/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:50:13 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

void	test_block1(t_test *test)
{
	utest(test_sa(), "test_sa", test);
	utest(test_sb(), "test_sb", test);
	utest(test_pa(), "test_pa", test);
	utest(test_pb(), "test_pb", test);
	utest(test_ra(), "test_ra", test);
	utest(test_rb(), "test_rb", test);
	utest(test_rra(), "test_rra", test);
	utest(test_rrb(), "test_rrb", test);
}

int	main(void)
{
	t_test	test;

	test.type = 1;
	test_init_struct(&test);
	test_show_start(&test);
	test_block1(&test);
	test_show_result(&test);
}
