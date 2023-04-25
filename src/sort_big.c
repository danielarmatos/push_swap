/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:27:29 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/25 19:50:10 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_max(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	j;
	int	len;

	j = 0;
	len = get_stack_len(stack_b);
	if (i <= (len / 2))
	{
		while (j < i)
		{
			rotate(stack_b, len, 'b');
			j++;
		}
	}
	else
	{
		i = len - i;
		j = 0;
		while (j < i)
		{
			reverse_rotate(stack_b, get_stack_len(stack_b), 'b');
			j++;
		}
	}
	push(stack_a, stack_b, 'b');
}

int	check_min_max(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		max;
	int		min;
	int		i;

	max = get_max(stack_b);
	min = get_min(stack_b);
	node = (*stack_b);
	i = 0;
	if ((*stack_a)->nb > max)
	{
		while (node->nb != max)
		{
			node = node->next;
			i++;
		}
		sort_min_max(stack_a, stack_b, i);
		return (1);
	}
	else if ((*stack_a)->nb < min)
	{
		while (node->nb != min)
		{
			node = node->next;
			i++;
		}
		i++;
		sort_min_max(stack_a, stack_b, i);
		return (1);
	}
	return (0);
}

void	f01(t_stack **stack_a, t_stack **stack_b, int min, int max)
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

void	start_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;

	while (get_stack_len(stack_a) != 0)
	{
		max = get_max(stack_b);
		min = get_min(stack_b);
		if ((*stack_b)->nb == max && (*stack_b)->prev->nb == min)
			f01(stack_a, stack_b, min, max);
		else if ((*stack_a)->nb > (*stack_b)->nb && (*stack_a)->nb < (*stack_b)->prev->nb)
			push(stack_a, stack_b, 'b');
		else if ((*stack_a)->next->nb > (*stack_b)->nb && (*stack_a)->next->nb < (*stack_b)->prev->nb)
		{
			swap(stack_a, 'a');
			push(stack_a, stack_b, 'b');
		}
		else if ((*stack_a)->prev->nb > (*stack_b)->nb && (*stack_a)->prev->nb < (*stack_b)->prev->nb)
		{
			reverse_rotate(stack_a, get_stack_len(stack_a), 'a');
			push(stack_a, stack_b, 'b');
		}
		else
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
