
#include "util.h"

// calculate maximum possible square and save position

void	cal_mx_sqr(t_mx_sqr *mx_sqr, int **n_mtrx, t_inf_map *inf_map)
{
	int	i;
	int	j;

	i = 1;
	mx_sqr->size = 1;
	while (i < inf_map->row)
	{
		j = 1;
		while (j < inf_map->col)
		{
			if (n_mtrx[i][j] == 1)
			{
				n_mtrx[i][j] = ft_min(n_mtrx[i -1][j], n_mtrx[i][j -1], \
					n_mtrx[i -1][j -1]) + 1;
				if (n_mtrx[i][j] > mx_sqr->size)
				{
					mx_sqr->size = n_mtrx[i][j];
					mx_sqr->position[0] = i;
					mx_sqr->position[1] = j;
				}
			}
			j++;
		}
		i++;
	}
}

//allocates memory for character array

char	**def_c_mtrx(t_inf_map *inf_map)
{
	int		i;
	char	**c_mtrx;

	c_mtrx = (char **)malloc(inf_map->row * 8);
	i = 0;
	while (i < inf_map->row)
	{
		c_mtrx[i] = (char *)malloc(inf_map->col * 1);
		i++;
	}
	return (c_mtrx);
}

//prepare the largest possible square for printing

void	print_mx_sqr(char **c_mtrx, t_mx_sqr *mx_sqr, t_inf_map *inf_map)
{
	int	x;
	int	y;
	int	x_rev;
	int	y_rev;

	x = 0;
	x_rev = mx_sqr->position[0];
	while (x < mx_sqr->size)
	{
		y_rev = mx_sqr->position[1];
		y = 0;
		while (y < mx_sqr->size)
		{
			c_mtrx[x_rev][y_rev] = inf_map->symbol[2];
			y_rev--;
			y++;
		}
		x_rev--;
		x++;
	}
}

//recovers the symbols in their original positions

void	sym(char **c_mtrx, int **n_mtrx, t_inf_map *inf_map, t_mx_sqr *mx_sqr)
{
	int	i;
	int	j;

	i = 0;
	while (i < inf_map->row)
	{
		j = 0;
		while (j < inf_map->col)
		{
			if (n_mtrx[i][j] > 0)
				c_mtrx[i][j] = inf_map->symbol[0];
			else
				c_mtrx[i][j] = inf_map->symbol[1];
			if (i == mx_sqr->position[0] && j == mx_sqr->position[1])
				print_mx_sqr(c_mtrx, mx_sqr, inf_map);
			j++;
		}
		i++;
	}
}