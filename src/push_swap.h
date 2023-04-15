/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:25:19 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/15 17:01:50 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				first;
}					t_stack;

int		check_doubles(int *arr, int len);
int		*convert_to_int(char **arr, int len);
int		check_if_numbers(char **arr, int len);

void	create_linked_list(int *int_arr, int len);
t_stack	*new_node(int nb, t_stack *next_stack);
void	sort_list(t_stack *head, int len);

void	swap_a(t_stack *stack);
void	rra(t_stack *stack, int len);

#endif
