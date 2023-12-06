
#include "util.h"

//allocates memory to the numeric array

int	**def_n_mtrx(t_inf_map *inf_map)
{
	int	i;
	int	j;
	int	**n_mtrx;

	i = 0;
	j = 0;
	n_mtrx = (int **)malloc(inf_map->row * 8);
	while (i < inf_map->row)
	{
		n_mtrx[i] = (int *)malloc(inf_map->col * 4);
		i++;
	}
	i = 0;
	while (i < inf_map->row)
	{
		j = 0;
		while (j < inf_map->col)
		{
			n_mtrx[i][j] = -1;
			++j;
		}
		++i;
	}
	return (n_mtrx);
}


int	ft_min(int x, int y, int z)
{
	int	min;

	min = x;
	if (min > y)
	{
		min = y;
	}
	else if (z < min)
	{
		min = z;
	}
	return (min);
}

int	valid_file(char *name, t_inf_map *inf_map)
{
	inf_map->file = open_file(name);
	if (inf_map->file == -1)
		return (1);
	inf_map->col = 0;
	inf_map->row = 0;
	if (check_info(inf_map) != 0)
		return (1);
	if (close_file(inf_map->file) != 0)
		return (1);
	return (0);
}

int	close_file(int file)
{
	if (close(file) == -1)
	{
		return (1);
	}
	return (0);
}