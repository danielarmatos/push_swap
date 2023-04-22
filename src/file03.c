/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:45:51 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/22 13:30:43 by dreis-ma         ###   ########.fr       */
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

void	sort_pushed(t_stack **stack_a, t_stack **stack_b, char name)
{
	t_stack	*node;
	int		len;
	int		nb;
	int		i;
	int 	j;

	node = (*stack_b)->next;
	len = get_stack_len(stack_b);
	nb = (*stack_b)->nb;
	i = 1;

	if (nb < node->nb && nb > node->next->nb)
	{
		swap(stack_b, name);
		return ;
	}
	else
	{
		while (i <= len)
		{
			if (nb < node->nb)
			{
				node = node->next;
				i++;
			}
			else
				break ;
		}
	}
	push(stack_b, stack_a, 'a');
	if ((i + 1) <= (len / 2))
	{
		j = i;
		i = 1;
		while (i < j)
		{
			rotate(stack_b, get_stack_len(stack_b), 'b');
			i++;
		}
		push(stack_a, stack_b, 'b');
		while ((*stack_b)->nb != get_max(stack_b))
		{
			reverse_rotate(stack_b, get_stack_len(stack_b), 'b');
		}
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
		while ((*stack_b)->nb != get_max(stack_b))
		{
			rotate(stack_b, get_stack_len(stack_b), 'b');
		}
	}
}

void	sort_middle(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;
	//int	middle;

//	middle = (get_stack_len(stack_a) / 2);
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
			push(stack_a, stack_b, 'b');
			sort_pushed(stack_a, stack_b, 'b');
		}
	}
	while (get_stack_len(stack_b) != 0)
		push(stack_b, stack_a, 'a');
}