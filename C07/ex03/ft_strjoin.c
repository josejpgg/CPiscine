/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:12:54 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/30 20:12:55 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	if (size == 0)
	{
		result = (char *)malloc(size);
		return (result);
	}
	result = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i != size - 1)
		{
			result = ft_strcat(result, sep);
		}
		i++;
	}
	return (result);
}
/*
#include <stdio.h>
int main (void)
{
    char *str[] = {"abc", "123", "_+-"};
    int size = 3;
    char *sep = "+";

    char *result = ft_strjoin(size, str, sep);
    printf("%s",result);
	free(result);
	return (0);
}
*/