/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:30:18 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/26 17:30:20 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	sort_values(char **str, int size, int time)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < size - 1)
	{
		if (ft_strcmp(str[i], str[i + 1]) > 0)
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
		}
		i++;
	}
	if (time <= size)
	{
		sort_values(str, size, time + 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	sort_values(argv, argc, 1);
	i = 0;
	while (i < argc - 1)
	{
		i++;
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
	return (0);
}
