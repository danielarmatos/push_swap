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

void	swap_a(t_stack *stack)
{
	int	temp;

	temp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = temp;
	ft_printf("sa\n");
}

void	rra(t_stack *stack, int len)
{
	int	temp1;
	int	i;
	//int	temp2;

	i = 0;
	temp1 = 0;
	ft_printf("\nrra\n");
	//while (len > 0)
	while (i < 3)
	{
		stack->nb = temp1;
		temp1 = stack->next->nb;
		stack->next->nb = stack->nb;
		stack = stack->next;
		len--;
		i++;
		ft_printf("%i, %i\n", stack->nb, stack->next->nb);
	}
}
