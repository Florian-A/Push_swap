
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:45:34 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

int	test_ft_atoi(void)
{
	char	*s1;

	s1 = "";
	if (ft_atoi(s1) != 0)
		return (-1);
	s1 = "   -15";
	if (ft_atoi(s1) != -15)
		return (-1);
	s1 = "++187";
	if (ft_atoi(s1) != 0)
		return (-1);
	s1 = "598+598";
	if (ft_atoi(s1) != 598)
		return (-1);
	s1 = "\200";
	if (ft_atoi(s1) != 0)
		return (-1);
	s1 = "-2147483648";
	if (ft_atoi(s1) != -2147483648)
		return (-1);
	s1 = "2147483647";
	if (ft_atoi(s1) != 2147483647)
		return (-1);
	return (0);
}
