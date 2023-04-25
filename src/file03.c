/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:45:51 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/25 18:42:04 by dreis-ma         ###   ########.fr       */
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

void	prepare_to_push(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	t_stack	*node;
	int		i;

	node = (*stack_a);
	i = 0;
	while (node->nb != utils->nb)
	{
		node = node->next;
		i++;
	}
	if (i > (utils->len_a / 2))
		while ((*stack_a)->nb != utils->nb)
			reverse_rotate(stack_a, utils->len_a, 'a');
	else
		while ((*stack_a)->nb != utils->nb)
			rotate(stack_a, utils->len_a, 'a');
	i = 0;
	if (utils->nb_index_b > (utils->len_b / 2))
		while (!((*stack_a)->nb > (*stack_b)->nb && (*stack_a)->nb < (*stack_b)->prev->nb))
			reverse_rotate(stack_b, get_stack_len(stack_b), 'b');
	else
		while (!((*stack_a)->nb > (*stack_b)->nb && (*stack_a)->nb < (*stack_b)->prev->nb))
			rotate(stack_b, get_stack_len(stack_b), 'b');
	push(stack_a, stack_b, 'b');
}

t_utils	*setup_utils(t_stack **stack_a, t_stack **stack_b)
{
	t_utils	*utils;

	utils = malloc (sizeof(t_utils));
	utils->len_b = get_stack_len(stack_b);
	utils->len_a = get_stack_len(stack_a);
	utils->max = get_max(stack_b);
	utils->min = get_min(stack_b);
	utils->curr_moves = 0;
	return (utils);
}

void	check_best_move2(t_stack *node_a, t_stack *node_b, t_utils *utils)
{
	int	mov;
	int	i;

	i = 1;
	while (!(node_a->nb < node_b->nb && node_a->nb > node_b->next->nb))
	{
		i++;
		node_b = node_b->next;
	}
	mov = i;
	if (mov > (utils->len_b / 2))
		mov = utils->len_b - mov;
	mov = mov + utils->curr_moves;
	if (!utils->best_moves || mov < utils->best_moves)
	{
		utils->nb_index_b = i;
		utils->best_moves = mov;
		utils->nb = node_a->nb;
	}
}

void	check_best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;
	t_stack	*node_b;
	t_utils	*utils;
	int		i;

	utils = setup_utils(stack_a, stack_b);
	if (check_min_max(stack_a, stack_b) == 1)
		return ;
	node_a = (*stack_a);
	i = 0;
	while (i <= (utils->len_a / 2))
	{
		node_b = (*stack_b);
		if (node_a->nb < utils->max && node_a->nb > utils->min)
			check_best_move2(node_a, node_b, utils);
		utils->curr_moves = utils->curr_moves + 1;
		if (i == (utils->len_a / 4))
		{
			utils->curr_moves = 1;
			node_a = (*stack_a)->prev;
		}
		else if (i < (utils->len_a / 4))
			node_a = node_a->next;
		else
			node_a = node_a->prev;
		i++;
	}
	prepare_to_push(stack_a, stack_b, utils);
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
				//prepare_to_push(stack_a, stack_b);
				check_best_move(stack_a, stack_b);
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
			//prepare_to_push(stack_a, stack_b);
			check_best_move(stack_a, stack_b);
	}
	while (get_stack_len(stack_b) != 0)
		push(stack_b, stack_a, 'a');
	sort_end(stack_a);
}