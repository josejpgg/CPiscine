/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:42:17 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/26 18:42:19 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*result;
	int	i;

	if (min > max)
	{
		return (0);
	}
	size = max - min;
	result = (int *)malloc(sizeof(int) * (size + 1));
	i = 0;
	while (i < size)
	{
		result[i] = min;
		min++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main (void)
{
	int min = -3;
	int max = 2;
	int *str = ft_range(min,max);
	int i = 0;

	while (i < (max - min))
	{
		printf("%i\n", str[i]);
		i++;
	}
	return (0);
}
*/