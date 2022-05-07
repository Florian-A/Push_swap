/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[], char **env)
{
	t_push_swap	push_swap;

	(void)env;
	init_s_stack(&push_swap);
	if (!fill_stack(&push_swap, &argv[1]))
	{
		ft_dprintf(2, "Error\n");
		cleaning(&push_swap);
		exit (EXIT_FAILURE);
	}
	indexing_stack(&push_swap);
	if (argc - 1 == 2)
		sort_2(&push_swap);
	else if (argc - 1 == 3)
		sort_3(&push_swap);
	else if (argc - 1 == 4)
		sort_4(&push_swap);
	else if (argc - 1 == 5)
		sort_5(&push_swap);
	else
		radix(&push_swap);
	cleaning(&push_swap);
	exit(EXIT_SUCCESS);
}
