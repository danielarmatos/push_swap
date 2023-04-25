/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:27:47 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/25 19:29:00 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->nb > (*stack)->next->nb)
		swap(stack, 'a');
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->nb;
	b = (*stack)->next->nb;
	c = (*stack)->next->next->nb;
	if (a < b && b < c)
		return ;
	if (a < b && b > c && a < c)
	{
		reverse_rotate(stack, 3, 'a');
		swap(stack, 'a');
	}
	else if (a > b && b < c && a < c)
		swap(stack, 'a');
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, 3, 'a');
	else if (a > b && b > c && a > c)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 3, 'a');
	}
	else
		rotate(stack, 3, 'a');
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	max = get_max(stack_a);
	min = get_min(stack_a);
	while (i < 4)
	{
		if ((*stack_a)->nb == max || (*stack_a)->nb == min)
		{
			push(stack_a, stack_b, 'b');
			break ;
		}
		else
			rotate(stack_a, (get_stack_len(stack_a)), 'a');
		i++;
	}
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		rotate(stack_a, 5, 'a');
}

void	sort_five_2(t_stack **stack_a, t_stack **stack_b)
{
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		rotate(stack_a, 5, 'a');
	push(stack_b, stack_a, 'a');
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		rotate(stack_a, 5, 'a');
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	max;
	int	min;
	int	x;

	i = 0;
	x = 0;
	max = get_max(stack_a);
	min = get_min(stack_a);
	while (i < 5 && x < 2)
	{
		if ((*stack_a)->nb == max || (*stack_a)->nb == min)
		{
			push(stack_a, stack_b, 'b');
			x++;
		}
		else
			rotate(stack_a, (get_stack_len(stack_a)), 'a');
		i++;
	}
	sort_five_2(stack_a, stack_b);
}
