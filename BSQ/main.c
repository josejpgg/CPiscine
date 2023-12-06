/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrentero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:18:04 by jrentero          #+#    #+#             */
/*   Updated: 2023/11/29 16:44:43 by jrentero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	map_error()
{
	write(1, "map error\n", 10);
}

int	run_bsq(char *name, t_inf_map *inf_map, t_mx_sqr *mx_sqr)
{
	char		**c_mtrx;
	int			**n_mtrx;

	if (valid_file(name, inf_map) != 0)
	{
		return (1);
	}
	n_mtrx = def_n_mtrx(inf_map);
	if (load_map(name, n_mtrx, inf_map) != 0)
	{
		return (1);
	}
	cal_mx_sqr(mx_sqr, n_mtrx, inf_map);
	c_mtrx = def_c_mtrx(inf_map);
	sym(c_mtrx, n_mtrx, inf_map, mx_sqr);
	print_c_mtrx(c_mtrx, inf_map);
	free(n_mtrx);
	free(c_mtrx);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_mx_sqr	*mx_sqr;
	t_inf_map	*inf_map;

	inf_map = (t_inf_map *)malloc(16);
	mx_sqr = (t_mx_sqr *)malloc(12);
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (run_bsq(argv[i], inf_map, mx_sqr) != 0)
			{
				map_error();
				return (0);
			}
			free_mx_sqr(mx_sqr);
			free_inf_map(inf_map);
			i++;
		}
	}
	free(mx_sqr);
	free(inf_map);
	return (0);
}
