/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:33:00 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/27 20:05:54 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	curr_b_rev;

	i = 1;
	curr_b_rev = 0;
	while (!(node_a->nb < node_b->nb && node_a->nb > node_b->next->nb))
	{
		i++;
		node_b = node_b->next;
	}
	mov = i;
	if (mov > (utils->len_b / 2))
	{
		mov = utils->len_b - mov;
		curr_b_rev = 1;
	}
	if (curr_b_rev == utils->curr_a_rev)
	{
		if (utils->curr_moves > mov)
			mov = utils->curr_moves;
	}
	else
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
	node_a = (*stack_a);
	i = 0;
	utils->curr_a_rev = 0;
	while (i <= (utils->len_a))
	{
		node_b = (*stack_b);
		if (node_a->nb < utils->max && node_a->nb > utils->min)
			check_best_default(node_a, node_b, utils);
		else
			check_best_min_max(node_a, node_b, utils);
		utils->curr_moves = utils->curr_moves + 1;
		if (i == (utils->len_a / 2))
		{
			utils->curr_a_rev = 1;
			utils->curr_moves = 1;
			node_a = (*stack_a)->prev;
		}
		else if (i < (utils->len_a / 2))
			node_a = node_a->next;
		else
			node_a = node_a->prev;
		i++;
	}
	prepare_to_push(stack_a, stack_b, utils);
}
