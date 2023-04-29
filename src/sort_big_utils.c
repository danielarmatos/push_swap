/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:29:54 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/29 14:29:50 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rotations_02(t_utils *utils)
{
	while (utils->rrb > 0)
	{
		ft_printf("rrb\n");
		utils->rrb--;
	}
	while (utils->ra > 0)
	{
		ft_printf("ra\n");
		utils->ra--;
	}
	while (utils->rb > 0)
	{
		ft_printf("rb\n");
		utils->rb--;
	}
}

void	print_rotations(t_utils *utils)
{
	while (utils->rra > 0 && utils->rrb > 0)
	{
		ft_printf("rrr\n");
		utils->rra--;
		utils->rrb--;
	}
	while (utils->ra > 0 && utils->rb > 0)
	{
		ft_printf("rr\n");
		utils->ra--;
		utils->rb--;
	}
	while (utils->rra > 0)
	{
		ft_printf("rra\n");
		utils->rra--;
	}
	print_rotations_02(utils);
}

void	sort_end(t_stack **stack_a)
{
	int		min;
	int		i;
	int		len;
	t_stack	*node;

	i = 0;
	min = get_min(stack_a);
	node = (*stack_a);
	len = get_stack_len(stack_a);
	while (node->nb != min)
	{
		node = node->next;
		i++;
	}
	if (i <= (len / 2))
		while ((*stack_a)->nb != min)
			rotate(stack_a, len, 'a');
	else
		while ((*stack_a)->nb != min)
			reverse_rotate(stack_a, len, 'a');
}

t_utils	*setup_utils(t_stack **stack_a, t_stack **stack_b)
{
	t_utils	*utils;

	utils = malloc (sizeof(t_utils));
	utils->len_b = get_stack_len(stack_b);
	utils->len_a = get_stack_len(stack_a);
	utils->max = get_max(stack_b);
	utils->min = get_min(stack_b);
	utils->curr_moves = 0;
	utils->nb_index_a = 0;
	utils->nb_index_b = 0;
	utils->best_moves = 0;
	utils->nb = 0;
	utils->ra = 0;
	utils->rb = 0;
	utils->rra = 0;
	utils->rrb = 0;
	return (utils);
}
