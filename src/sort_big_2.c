/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:33:00 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/25 20:36:34 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_min_max(t_stack **stack_b, t_utils *utils)
{
	if (utils->nb_index_b > (utils->len_b / 2))
		while ((*stack_b)->nb != utils->max)
			reverse_rotate(stack_b, get_stack_len(stack_b), 'b');
	else
		while ((*stack_b)->nb != utils->max)
			rotate(stack_b, get_stack_len(stack_b), 'b');
}

void	rotate_default(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	if (utils->nb_index_b > (utils->len_b / 2))
		while (!((*stack_a)->nb > (*stack_b)->nb && (*stack_a)->nb < (*stack_b)->prev->nb))
			reverse_rotate(stack_b, get_stack_len(stack_b), 'b');
	else
		while (!((*stack_a)->nb > (*stack_b)->nb && (*stack_a)->nb < (*stack_b)->prev->nb))
			rotate(stack_b, get_stack_len(stack_b), 'b');
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
	if ((*stack_a)->nb < utils->max && (*stack_a)->nb > utils->min)
		rotate_default(stack_a, stack_b, utils);
	else
		rotate_min_max(stack_b, utils);
	push(stack_a, stack_b, 'b');
}

/* The function check_best_min_max is used when the number from the stack_a
that we are currently evaluating is greater or smaller than the max or min value
from the stack_b */

void	check_best_min_max(t_stack *node_a, t_stack *node_b, t_utils *utils)
{
	int	mov;
	int	i;

	i = 1;
	while (node_b->nb != utils->max)
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

void	check_best_default(t_stack *node_a, t_stack *node_b, t_utils *utils)
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
			check_best_default(node_a, node_b, utils);
		else
			check_best_min_max(node_a, node_b, utils);
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

