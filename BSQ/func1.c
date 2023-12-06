
#include "util.h"

//print the resulting matrix

void	print_c_mtrx(char **c_mtrx, t_inf_map *inf_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < inf_map->row)
	{
		j = 0;
		while (j < inf_map->col)
		{
			write(1, &c_mtrx[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

//free memory of matrix, map and square

void	free_n_mtrx(int **n_mtrx, t_inf_map *inf_map)
{
	int	i;

	i = 0;
	while (i < inf_map->row)
	{
		free(n_mtrx[i]);
		i++;
	}
	free(n_mtrx);
	n_mtrx = 0;
}

void	free_c_mtrx(char **c_mtrx, t_inf_map *inf_map)
{
	int	i;

	i = 0;
	while (i < inf_map->row)
	{
		free(c_mtrx[i]);
		i++;
	}
	free(c_mtrx);
	c_mtrx = NULL;
}

void	free_inf_map(t_inf_map *inf_map)
{
	inf_map->file = 0;
	inf_map->row = 0;
	inf_map->col = 0;
	inf_map->symbol[2] = 0;
	inf_map->symbol[1] = 0;
	inf_map->symbol[0] = 0;
}

void	free_mx_sqr(t_mx_sqr *mx_sqr)
{
	mx_sqr->size = 0;
	mx_sqr->position[1] = 0;
	mx_sqr->position[0] = 0;
}