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

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*result;
	int	i;

	if (min > max)
	{
		*range = NULL;
		return (0);
	}
	result = (int *)malloc((max - min) + 1);
	if (result == NULL)
	{
		*range = NULL;
		return (-1);
	}
	*range = result;
	i = 0;
	while (i < (max - min))
	{
		result[i] = min;
		min++;
		i++;
	}
	result[i] = '\0';
	return (i);
}
/*
#include <stdio.h>
int main (void)
{
	int min = 6;
	int max = 5;
    int *str;
	int size = ft_ultimate_range(&str,min,max);
	int i = 0;
	while (i < size)
	{
		printf("%i\n", str[i]);
		i++;
	}
	if (str == NULL)
	{
		printf("%s\n", "NULL");
	}
	printf("%i\n", size);
	return (0);
}
*/