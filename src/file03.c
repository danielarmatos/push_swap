/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:45:51 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/20 22:07:33 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_middle(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		swap(stack_b, 'b');
	while (get_stack_len(stack_a) > 3)
	{
		max = get_max(stack_b);
		min = get_min(stack_b);
		if ((*stack_a)->nb > max || (*stack_a)->nb < min)
		{
			push(stack_a, stack_b, 'b');
			if ((*stack_b)->nb < min)
				rotate(stack_b, get_stack_len(stack_b), 'b');
		}
		else if ((*stack_a)->prev->nb > max || (*stack_a)->prev->nb < min)
		{
			reverse_rotate(stack_a, get_stack_len(stack_a), 'a');
			push(stack_a, stack_b, 'b');
			if ((*stack_b)->nb < min)
				rotate(stack_b, get_stack_len(stack_b), 'b');
		}
		else
			rotate(stack_a, get_stack_len(stack_a), 'a');
	}
}