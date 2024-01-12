/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:44:07 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/25 22:44:08 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
	{
		return (0);
	}
	i = 2;
	while (i * i < nb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	result;

	if (nb < 2)
	{
		return (2);
	}
	result = nb;
	while (!ft_is_prime(result))
	{
		result++;
	}
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
    printf("%i\n",ft_find_next_prime(45));
    return 0;
}
*/