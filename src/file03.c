/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:45:51 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/22 19:55:56 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_end(t_stack **stack_a)
{
	int		min;
	int		i;
	int		len;
	t_stack	*node;

	i = 0;
	min = get_min(stack_a);
	node = (*stack_a);
	len = get_stack_len(stack_a);
	while (node->nb != min)
	{
		node = node->next;
		i++;
	}
	if (i <= (len / 2))
		while ((*stack_a)->nb != min)
			rotate(stack_a, len, 'a');
	else
		while ((*stack_a)->nb != min)
			reverse_rotate(stack_a, len, 'a');
}

void	sort_min_max(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	j;
	int	len;

	j = 1;
	len = get_stack_len(stack_b);
	while (j < i)
	{
		rotate(stack_b, len, 'b');
		j++;
	}
/*	if (i <= (len / 2))
	{
		while (j <= i)
		{
			rotate(stack_b, len, 'b');
			j++;
		}
	}
	else
	{
		while (j < i)
		{
			reverse_rotate(stack_b, get_stack_len(stack_b), 'b');
			j++;
		}
	}*/
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
	i = 1;
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

void	prepare_to_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		len;
	int		nb;
	int		i;
	int		j;

	if (check_min_max(stack_a, stack_b) == 1)
		return ;
	node = (*stack_b);
	len = get_stack_len(stack_b);
	nb = (*stack_a)->nb;
	i = 1;
	j = 0;
	while (!(nb < node->nb && nb > node->next->nb))
	{
		i++;
		node = node->next;
	}
	while (j < i)
	{
		rotate(stack_b, get_stack_len(stack_b), 'b');
		j++;
	}
	push(stack_a, stack_b, 'b');
	/*if (i <= (len / 2))
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
	}*/
}

void	sort_middle(t_stack **stack_a, t_stack **stack_b)
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
		if ((*stack_b)->nb == max && (*stack_b)->prev->nb == min)
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
				prepare_to_push(stack_a, stack_b);
		}
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
			prepare_to_push(stack_a, stack_b);
	}
	while (get_stack_len(stack_b) != 0)
		push(stack_b, stack_a, 'a');
	sort_end(stack_a);
	/*min = get_min(stack_a);
	while ((*stack_a)->nb != min)
		rotate(stack_a, get_stack_len(stack_a), 'a');*/
}