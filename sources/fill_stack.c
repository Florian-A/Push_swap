/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_duplica(t_list *lst, char *nb);
static int	create_stack(t_push_swap *push_swap, int stack, char *str);
static int	add_to_stack(t_push_swap *push_swap, int stack, char *str);
static void	del_extras_zero(char **str);

int	fill_stack(t_push_swap *push_swap, char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isnbr(argv[i]))
			return (0);
		del_extras_zero(&argv[i]);
		if (ft_strlen(argv[i]) > 11 || is_duplica(push_swap->stack[0], argv[i]) \
			|| ft_atol(argv[i]) < -2147483648 || ft_atol(argv[i]) > 2147483647)
			return (0);
		if (push_swap->stack[0] == NULL)
		{
			if (!create_stack(push_swap, 0, argv[i]))
				return (0);
		}
		else
		{
			if (!add_to_stack(push_swap, 0, argv[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	is_duplica(t_list *lst, char *nb)
{
	t_list	*lst1;

	lst1 = lst;
	while (lst1)
	{
		if (((t_block *)lst1->content)->nb == ft_atoi(nb))
			return (1);
		lst1 = lst1->next;
	}
	return (0);
}

static void	del_extras_zero(char **str)
{
	int	is_neg;

	if (str[0][0] == '-' || str[0][0] == '+')
	{
		is_neg = 0;
		if (str[0][0] == '-')
			is_neg = 1;
		while (str[0][1] == '0')
			str[0] = &str[0][1];
		if (is_neg)
			str[0][0] = '-';
		else
			str[0][0] = '+';
	}
	else
	{
		while (str[0][0] == '0')
			str[0] = &str[0][1];
	}
}

static int	create_stack(t_push_swap *push_swap, int stack, char *str)
{
	t_block	*new_block;

	new_block = ft_calloc(sizeof(t_block), 1);
	if (!new_block)
		return (0);
	new_block->nb = ft_atoi(str);
	push_swap->stack[stack] = ft_lstnew(new_block);
	if (!push_swap->stack[0])
		return (0);
	return (1);
}

static int	add_to_stack(t_push_swap *push_swap, int stack, char *str)
{
	t_list	*new_lst;
	t_block	*new_block;

	new_block = ft_calloc(sizeof(t_block), 1);
	if (!new_block)
		return (0);
	new_block->nb = ft_atoi(str);
	new_lst = ft_lstnew(new_block);
	if (!new_lst)
		return (0);
	ft_lstadd_back(&push_swap->stack[stack], new_lst);
	return (1);
}
