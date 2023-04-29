/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:14:45 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/29 14:58:25 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_min_max(t_stack **stack_b, t_utils *utils)
{
	if (utils->nb_index_b > (utils->len_b / 2))
	{
		while ((*stack_b)->nb != utils->max)
		{
			reverse_rotate(stack_b, get_stack_len(stack_b), 'x');
			utils->rrb++;
		}
	}
	else
	{
		while ((*stack_b)->nb != utils->max)
		{
			rotate(stack_b, get_stack_len(stack_b), 'x');
			utils->rb++;
		}
	}
}

void	rotate_default(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	if (utils->nb_index_b > (utils->len_b / 2))
	{
		while (!((*stack_a)->nb > (*stack_b)->nb
				&& (*stack_a)->nb < (*stack_b)->prev->nb))
		{
			reverse_rotate(stack_b, get_stack_len(stack_b), 'x');
			utils->rrb++;
		}
	}
	else
	{
		while (!((*stack_a)->nb > (*stack_b)->nb
				&& (*stack_a)->nb < (*stack_b)->prev->nb))
		{
			rotate(stack_b, get_stack_len(stack_b), 'x');
			utils->rb++;
		}
	}
}

void	prepare_to_push_2(t_stack **stack_a, t_utils *utils, int i)
{
	if (i > (utils->len_a / 2))
	{
		while ((*stack_a)->nb != utils->nb)
		{
			reverse_rotate(stack_a, utils->len_a, 'x');
			utils->rra++;
		}
	}
	else
	{
		while ((*stack_a)->nb != utils->nb)
		{
			rotate(stack_a, utils->len_a, 'x');
			utils->ra++;
		}
	}
}

void	prepare_to_push(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	t_stack	*node;
	int		i;

	node = (*stack_a);
	i = 0;
	while (node->nb != utils->nb)
	{
		node = node->next;
		i++;
	}
	prepare_to_push_2(stack_a, utils, i);
	if ((*stack_a)->nb < utils->max && (*stack_a)->nb > utils->min)
		rotate_default(stack_a, stack_b, utils);
	else
		rotate_min_max(stack_b, utils);
	print_rotations(utils);
	push(stack_a, stack_b, 'b');
}
