/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:36:38 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/22 15:19:21 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*convert_to_int(char **arr, int len)
{
	int	*int_arr;
	int	i;

	i = 0;
	int_arr = (int *) ft_calloc(len, sizeof(int));
	if (!int_arr)
		return (0);
	while (i < len)
	{
		//ft_printf("%s\n", arr[i]);
		if (arr[i][0] == '-')
			if (!arr[i][1])
				return (0);
		if (ft_atol(arr[i]) < INT_MAX && ft_atol(arr[i]) > INT_MIN)
			int_arr[i] = ft_atol(arr[i]);
		else
		{
			ft_printf("\nError\n%s is not an int.\n", arr[i]);
			free(int_arr);
			return (0);
		}
		i++;
	}
	return (int_arr);
}

int	check_if_numbers(char **arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (arr[i][j])
		{
			if ((arr[i][j] >= '0' && arr[i][j] <= '9') ||
				arr[i][j] == '-' || arr[i][j] == '+')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
