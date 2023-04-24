/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:25:19 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/24 17:49:30 by dreis-ma         ###   ########.fr       */
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
}					t_stack;

typedef struct s_utils
{
	struct s_stack	*stack;
	int				nb;
	int				best_moves;
	int				reverse;
	int				len;
}					t_utils;

int		check_doubles(int *arr, int len);
int		*convert_to_int(char **arr, int len);
int		check_if_numbers(char **arr, int len);

void	create_linked_list(int *int_arr, int len);
t_stack	*new_node(int nb, t_stack *next_stack);
void	sort_list(t_stack **stack_a, int len);

void	swap(t_stack **stack, char name);
void	rotate(t_stack **stack, int len, char name);
void	reverse_rotate(t_stack **stack, int len, char name);
void	push(t_stack **stack_1, t_stack **stack_2, char name);

int		get_stack_len(t_stack **stack);
int		get_max(t_stack **stack);
int		get_min(t_stack **stack);

void	sort_middle(t_stack **stack_a, t_stack **stack_b);

#endif
