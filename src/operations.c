/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:56:42 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/08 18:13:05 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char name)
{
	int	temp;

	temp = (*stack)->nb;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->next->nb = temp;
	if (name == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	rotate(t_stack **stack, int len, char name)
{
	int	temp1;
	int temp2;

	temp1 = (*stack)->next->nb;
	while (len > 0)
	{
		temp2 = (*stack)->nb;
		(*stack)->nb = temp1;
		temp1 = temp2;
		(*stack) = (*stack)->prev;
		len--;
	}
	if (name == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	reverse_rotate(t_stack **stack, int len, char name)
{
	int	temp1;
	int temp2;

	temp1 = (*stack)->prev->nb;
	while (len > 0)
	{
		temp2 = (*stack)->nb;
		(*stack)->nb = temp1;
		temp1 = temp2;
		(*stack) = (*stack)->next;
		len--;
	}
	if (name == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
/*
t_stack	*push(t_stack **stack_1, t_stack *stack_2, char name)
{
	t_stack	*temp;
	(void)stack_2;

	if (!stack_1)
		return (stack_1);
	temp = stack_1;
	stack_1 = temp->next;
	stack_1->prev = temp->prev;
	stack_1->prev->next = stack_1;
	ft_printf("lala: %i, %i, %i\n", stack_1->nb, temp->prev->nb, stack_1->prev->next->nb);
	if (name == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	return (stack_1);
}*/