/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:45:58 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/15 17:18:40 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	link_first(t_stack *head)
{
	t_stack *stack;

	stack = head;
	while (stack->next)
	{
		stack = stack->next;
	}
	stack->next = head;
	head->prev = stack;
}

void	push_list(t_stack **stack, int nb)
{
	t_stack	*temp;

	temp = (t_stack *) malloc(sizeof(t_stack));
	temp->nb = nb;
	temp->next = *stack;
	if (temp->next)
		temp->next->prev = temp;
	temp->first = 0;
	*stack = temp;
}

t_stack	*create_list(int *int_arr, int len)
{
	t_stack	*head;

	head = NULL;
	while (len > 0)
	{
		push_list(&head, int_arr[len - 1]);
		len--;
	}
	link_first(head);
	return (head);
}

void	create_linked_list(int *int_arr, int len)
{
	t_stack	*head;
	t_stack	*stack;
	int 	i;

	head = create_list(int_arr, len);
	head->first = 1;
	stack = head;
	ft_printf("linked list:\n");
	i = 0;
	while (i < len)
	{
		ft_printf("%i\n", stack->nb);
		stack = stack->next;
		i++;
	}
	head = sort_list(head, len);
	ft_printf("\nSorted:\n");
	i = 0;
	while (i < len)
	{
		stack = head;
		ft_printf("%i\n", head->nb);
		head = head->next;
		free (stack);
		i++;
	}
}
