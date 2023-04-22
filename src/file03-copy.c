/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:45:51 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/22 15:57:02 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
 */

int	check_min_max(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;

	max = get_max(stack_b);
	min = get_min(stack_b);
	if ((*stack_a)->nb > max)
		return (1);
	else if ((*stack_a)->nb < min)
}

void	prepare_to_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		len;
	int		nb;
	int		i;
	int		j;

	node = (*stack_b);
	len = get_stack_len(stack_b);
	nb = (*stack_a)->nb;
	i = 1;

	while (!(nb < node->nb && nb > node->next->nb))
	{
		i++;
		node = node->next;
	}
	if (i <= (len / 2))
	{
		j = i;
		i = 1;
		while (i < j)
		{
			rotate(stack_b, get_stack_len(stack_b), 'b');
			i++;
		}
		push(stack_a, stack_b, 'b');
	}
	else
	{
		j = len - i;
		i = 0;
		while (i < j)
		{
			reverse_rotate(stack_b, get_stack_len(stack_b), 'b');
			i++;
		}
		push(stack_a, stack_b, 'b');
	}
}

/*void	sort_middle(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		swap(stack_b, 'b');
	while (get_stack_len(stack_a) != 0)
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
		{
			if ((*stack_a)->nb < (*stack_b)->nb && (*stack_a)->nb > (*stack_b)->next->nb)
			{
				push(stack_a, stack_b, 'b');
				swap(stack_b, 'b');
			}
			else
			{
				prepare_to_push(stack_a, stack_b);
			}

		}
	}
	while (get_stack_len(stack_b) != 0)
		push(stack_b, stack_a, 'a');
}*/

void	sort_middle(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		swap(stack_b, 'b');
	while (get_stack_len(stack_a) != 0)
	{
		if (check_min_max(stack_a, stack_b) == 0)
		{
			if ((*stack_a)->nb > (*stack_b)->nb && (*stack_a)->nb < (*stack_b)->prev->nb)
				push(stack_a, stack_b, 'b');
			else if ((*stack_a)->prev->nb > (*stack_b)->nb && (*stack_a)->prev->nb < (*stack_b)->prev->nb) {
				reverse_rotate(stack_a, get_stack_len(stack_a), 'a');
				push(stack_a, stack_b, 'b');
			} else if ((*stack_a)->nb<(*stack_b)->nb && (*stack_a)->nb>(*stack_b)->next->nb) {
				push(stack_a, stack_b, 'b');
				swap(stack_b, 'b');
			} else
				prepare_to_push(stack_a, stack_b);
		}
	}
}