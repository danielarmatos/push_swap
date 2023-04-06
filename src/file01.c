/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:45:58 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/06 19:52:21 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_list(t_stack **stack, int nb)
{
    t_stack *temp;

    temp = (t_stack *) malloc(sizeof(t_stack));
    temp->nb = nb;
    temp->next = *stack;
    *stack = temp;
}

t_stack *create_list(int *int_arr, int len)
{
    t_stack *head;

    head = NULL;
    ft_printf("\nlen: %i\n", len);
    while (len > 0)
    {
        push_list(&head, int_arr[len - 1]);
        len--;
    }
    return (head);
}

void	create_linked_list(int *int_arr, int len)
{
	t_stack	*head;
	t_stack	*stack;

	head = create_list(int_arr, len);
	stack = head;
	ft_printf("\nlinked list:\n");
	while (stack)
	{
		ft_printf("%i\n", stack->nb);
		stack = stack->next;
	}
    while (head)
    {
        stack = head;
        head = head->next;
        free (stack);
    }
    free (head);
}