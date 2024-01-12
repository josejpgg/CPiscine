/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vclotet- <vclotet-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:39:26 by vclotet-          #+#    #+#             */
/*   Updated: 2023/11/12 17:15:52 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush_helper(int j, int x, int i, int y);

void	rush(int x, int y)
{
	int		i;
	int		j;

	i = 1;
	if (x < 1 || y < 0)
	{
		x = 0;
		y = 0;
	}
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			rush_helper(j, x, i, y);
			if (j == x)
				ft_putchar('\n');
			j++;
		}
		i++;
	}
}

void	rush_helper(int j, int x, int i, int y)
{
	if (i == 1 || i == y)
	{
		if (j == 1 || j == x)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
	}
	if (i > 1 && i < y)
	{
		if (j == 1 || j == x)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
	}
}
