/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:25:19 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/28 18:25:21 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int check_if_numbers(char **arr);

#endif
