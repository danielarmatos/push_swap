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

void	swap(t_stack *stack, char name)
{
	int	temp;

	temp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = temp;
	if (name == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	rotate(t_stack *stack, int len, char name)
{
	int	temp1;
	int temp2;

	temp1 = stack->next->nb;
	while (len > 0)
	{
		temp2 = stack->nb;
		stack->nb = temp1;
		temp1 = temp2;
		stack = stack->prev;
		len--;
	}
	if (name == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	reverse_rotate(t_stack *stack, int len, char name)
{
	int	temp1;
	int temp2;

	temp1 = stack->prev->nb;
	while (len > 0)
	{
		temp2 = stack->nb;
		stack->nb = temp1;
		temp1 = temp2;
		stack = stack->next;
		len--;
	}
	if (name == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

