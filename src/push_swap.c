/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:24:38 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/29 14:47:28 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	push_swap(char **arr)
{
	int	*int_arr;
	int	len;

	len = 0;
	while (arr[len])
		len++;
	if (check_if_numbers(arr, len) == 1)
	{
		int_arr = convert_to_int(arr, len);
		if (int_arr != 0)
		{
			if (check_doubles(int_arr, len) == 1)
				create_linked_list(int_arr, len);
			else
				write(2, "Error\n", 6);
		}
		free(int_arr);
	}
	else
		write(2, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	char	**arr;

	if (argc > 1)
	{
		if (argc == 2)
			arr = ft_split(argv[1], ' ');
		else
			arr = argv + 1;
		push_swap(arr);
		if (argc == 2)
			free_array(arr);
	}
	return (0);
}
