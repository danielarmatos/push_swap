/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:27:29 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/27 20:16:17 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_max(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	if ((*stack_a)->nb > max || (*stack_a)->nb < min)
		push(stack_a, stack_b, 'b');
	else if ((*stack_a)->next->nb > max || (*stack_a)->next->nb < min)
	{
		swap(stack_a, 'a');
		push(stack_a, stack_b, 'b');
	}
	else if ((*stack_a)->prev->nb > max || (*stack_a)->prev->nb < min)
	{
		reverse_rotate(stack_a, get_stack_len(stack_a), 'a');
		push(stack_a, stack_b, 'b');
	}
	else
		check_best_move(stack_a, stack_b);
}

void	sort_default(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->nb > (*stack_b)->nb
		&& (*stack_a)->nb < (*stack_b)->prev->nb)
		push(stack_a, stack_b, 'b');
	else if ((*stack_a)->next->nb > (*stack_b)->nb
		&& (*stack_a)->next->nb < (*stack_b)->prev->nb)
	{
		swap(stack_a, 'a');
		push(stack_a, stack_b, 'b');
	}
	else if ((*stack_a)->prev->nb > (*stack_b)->nb
		&& (*stack_a)->prev->nb < (*stack_b)->prev->nb)
	{
		reverse_rotate(stack_a, get_stack_len(stack_a), 'a');
		push(stack_a, stack_b, 'b');
	}
	else
		check_best_move(stack_a, stack_b);
}

void	start_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;

	while (get_stack_len(stack_a) != 0)
	{
		max = get_max(stack_b);
		min = get_min(stack_b);
		/*if ((*stack_b)->nb == max && (*stack_b)->prev->nb == min)
			sort_min_max(stack_a, stack_b, min, max);
		else
			sort_default(stack_a, stack_b);*/
		check_best_move(stack_a, stack_b);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		swap(stack_b, 'b');
	start_sorting(stack_a, stack_b);
	while (get_stack_len(stack_b) != 0)
		push(stack_b, stack_a, 'a');
	sort_end(stack_a);
}
