/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:38:38 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/25 19:23:39 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_len(t_stack **stack)
{
	t_stack	*node;
	int		nb;
	int		len;

	if ((*stack) == NULL)
		return (0);
	node = (*stack);
	nb = node->nb;
	len = 0;
	while (node->next->nb != nb)
	{
		len++;
		node = node->next;
	}
	len++;
	return (len);
}

int	get_max(t_stack **stack)
{
	t_stack	*node;
	int		max;
	int		len;

	len = get_stack_len(stack);
	node = (*stack);
	max = node->nb;
	while (len > 0)
	{
		if (node->nb > max)
			max = node->nb;
		node = node->next;
		len--;
	}
	return (max);
}

int	get_min(t_stack **stack)
{
	t_stack	*node;
	int		min;
	int		len;

	len = get_stack_len(stack);
	node = (*stack);
	min = node->nb;
	while (len > 0)
	{
		if (node->nb < min)
			min = node->nb;
		node = node->next;
		len--;
	}
	return (min);
}

int	check_if_sorted(t_stack *stack, int len)
{
	int	i;

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
