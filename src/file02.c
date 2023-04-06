/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:54:33 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/06 20:17:04 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_if_sorted(t_stack *stack)
{
    while (stack->next)
    {
        ft_printf("%i, %i\n", stack->nb, stack->next->nb);
        if (stack->nb > stack->next->nb)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    sort_list(t_stack *head, int len)
{
    t_stack	*stack;
    
    stack = head;
    if (check_if_sorted(head) == 1)
        ft_printf("List is sorted.");
    else
    {
        if (len == 2)
            sort_two(head);
        if (len == 3)
            sort_three(head);
        ft_printf("List is NOT sorted.");
    }
}