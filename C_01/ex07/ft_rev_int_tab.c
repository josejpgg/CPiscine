/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:29:40 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/12 17:44:27 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	j;
	int	x;
	int	tmp;

	tmp = 0;
	j = 0;
	x = size - 1;
	while (j < x)
	{	
		tmp = tab[j];
		tab[j] = tab[x];
		tab[x] = tmp;
		j++;
		x--;
	}
}
