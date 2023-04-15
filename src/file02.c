/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:54:33 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/11 19:54:55 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_five(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = push(stack_a, stack_b, 'a');
	return (stack_a);
}

t_stack	*sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int c;

	a = stack->nb;
	b = stack->next->nb;
	c = stack->next->next->nb;
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
	return (stack);
}

t_stack	*sort_two(t_stack *stack)
{
	if (stack->nb > stack->next->nb)
		swap(stack, 'a');
	return (stack);
}

int	check_if_sorted(t_stack *stack, int len)
{
	int i;

	i = 0;
	while (i < (len - 1))
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}


t_stack	*sort_list(t_stack *head, int len)
{
	t_stack *stack_b;

	stack_b = NULL;
	if (check_if_sorted(head, len) == 1)
	{
		ft_printf("\nList is sorted.");
		return (head);
	}
	else
	{
		ft_printf("\nList is NOT sorted.\n\n");
		if (len == 2)
			return (sort_two(head));
		if (len == 3)
			return (sort_three(head));
		if (len == 5)
			return (sort_five(head, stack_b));
		else
			return (head);
	}
}
