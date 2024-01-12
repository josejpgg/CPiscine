/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:52:00 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/26 15:52:01 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	atoti_sense(int sense)
{
	if ((sense % 2) == 0)
		sense = 1;
	else
		sense = -1;
	return (sense);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sense;

	i = 0;
	result = 0;
	sense = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sense++;
		}
		else if (str[i] < 48 || str[i] > 57)
		{
			if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
				break ;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * atoti_sense(sense));
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(void){
	printf("%d\n", ft_atoi("  \t  -+-+-+----234a1bc"));
}
*/