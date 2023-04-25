/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:25:19 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/25 19:31:34 by dreis-ma         ###   ########.fr       */
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
	int				nb;
	int				nb_index_b;
	int				best_moves;
	int				curr_moves;
	int				reverse;
	int				len_a;
	int				len_b;
	int				max;
	int				min;
}					t_utils;

int		check_doubles(int *arr, int len);
int		*convert_to_int(char **arr, int len);
int		check_if_numbers(char **arr, int len);

void	create_linked_list(int *int_arr, int len);
t_stack	*new_node(int nb, t_stack *next_stack);

int		check_if_sorted(t_stack *stack, int len);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

void	swap(t_stack **stack, char name);
void	rotate(t_stack **stack, int len, char name);
void	reverse_rotate(t_stack **stack, int len, char name);
void	push(t_stack **stack_1, t_stack **stack_2, char name);

int		get_stack_len(t_stack **stack);
int		get_max(t_stack **stack);
int		get_min(t_stack **stack);

void	sort_big(t_stack **stack_a, t_stack **stack_b);
int		check_min_max(t_stack **stack_a, t_stack **stack_b);
void	check_best_move(t_stack **stack_a, t_stack **stack_b);


void	sort_end(t_stack **stack_a);
t_utils	*setup_utils(t_stack **stack_a, t_stack **stack_b);

#endif
