/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:24:38 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/28 18:24:41 by dreis-ma         ###   ########.fr       */
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

int	check_doubles(int *arr, int len)
{
	int	i;
	int j;

	i = 0;
	while (i < len)
	{
		ft_printf("%i\n", arr[i]);
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
		int_arr[i] = ft_atoi(arr[i]);
		ft_printf("%i\n", int_arr[i]);
		i++;
	}
	return (int_arr);
}

int check_if_numbers(char **arr, int len)
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
			if ((arr[i][j] >= '0' && arr[i][j] <= '9') || arr[i][j] == '-' || arr[i][j] == '+')
				j++;
			else
				return (0);
		}
		i++;
	}
    return(1);
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
		ft_printf("All arguments are integers.\n");
		int_arr = convert_to_int(arr, len);
		if (check_doubles(int_arr, len) == 1)
			ft_printf("No duplicated numbers\n");
		else
			ft_printf("Error\nDuplicated numbers.\n");
		free(int_arr);
	}
	else
		ft_printf("Error\nSome arguments aren't integers.\n");
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
