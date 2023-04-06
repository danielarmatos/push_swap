/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:47:27 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/04/06 18:10:42 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long ft_atol(const char *str)
{
	long	i;
	long	value;
	long	r;

	i = 0;
	value = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			value = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	r = r * value;
	return (r);
}
/*
int	main(void)
{
	char str[] = "-1234";
	int val;
	int val2;

	val = atoi(str);
	val2 = ft_atoi(str);
	printf("%d", val);
	printf("\n%d", val2);

}*/
