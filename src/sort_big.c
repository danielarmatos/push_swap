/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:27:29 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/05/01 16:36:18 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		swap(stack_b, 'b');
	while (get_stack_len(stack_a) != 0)
		check_best_move(stack_a, stack_b);
	while (get_stack_len(stack_b) != 0)
		push(stack_b, stack_a, 'a');
	sort_end(stack_a);
}
