/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:22:40 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/16 19:22:44 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 65 || str[i] > 90)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
