/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:45:58 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/20 20:10:22 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	link_first(t_stack **stack)
{
	t_stack	*node;

	node = (*stack);
	while (node->next)
		node = node->next;
	node->next = (*stack);
	(*stack)->prev = node;
}

void	add_node(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	if (new_node->next)
		new_node->next->prev = new_node;
	*stack = new_node;
}

t_stack	*create_node(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->nb = nb;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	create_linked_list(int *int_arr, int len)
{
	t_stack	**stack_a;
	t_stack	*node;
	int		i;

	i = len;
	stack_a = (t_stack **) malloc(sizeof(t_stack *) * len);
	while (len > 0)
	{
		add_node(stack_a, create_node(int_arr[len - 1]));
		len--;
	}
	link_first(stack_a);
	len = i;
	i = 0;
	node = (*stack_a);
	while (i < len)
	{
	//	ft_printf("%i\n", node->nb);
		node = node->next;
		i++;
	}
	i = 0;
	get_stack_len(stack_a);
	get_max(stack_a);
	get_min(stack_a);
	sort_list(stack_a, len);
	node = (*stack_a);
	while (i < len)
	{
		node = (*stack_a);
	//	ft_printf("%i\n", (*stack_a)->nb);
		(*stack_a) = (*stack_a)->next;
		free (node);
		i++;
	}
	free(stack_a);
}
