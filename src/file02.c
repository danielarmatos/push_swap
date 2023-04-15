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

void	sort_three(t_stack *stack, int len)
{
	int	a;
	int	b;
	int c;

	a = stack->nb;
	b = stack->next->nb;
	c = stack->next->next->nb;
	if (a < b && b > c && a < c)
	{
		reverse_rotate(stack, len, 'a');
		swap(stack, 'a');
	}
	else if (a > b && b < c && a < c)
		swap(stack, 'a');
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, len, 'a');
	else if (a > b && b > c && a > c)
	{
		swap(stack, 'a');
		reverse_rotate(stack, len, 'a');
	}
	else
		rotate(stack, len, 'a');

	
}

void	sort_two(t_stack *stack)
{
	if (stack->nb > stack->next->nb)
		swap(stack, 'a');
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


void	sort_list(t_stack *head, int len)
{
	t_stack	*stack;

	stack = head;
	if (check_if_sorted(stack, len) == 1)
		ft_printf("\nList is sorted.");
	else
	{
		ft_printf("\nList is NOT sorted.\n\n");
		if (len == 2)
			sort_two(stack);
		if (len == 3)
			sort_three(head, len);
		/*if (len > 3)
			rotate(head, len, 'a');*/
	}
}
