
#include "util.h"

int	load_map(char *name, int **n_matrix, t_inf_map *inf_map)
{
	inf_map->file = open_file(name);
	if (inf_map->file == -1)
	{
		return (1);
	}
	if (set_n_matrix(inf_map, n_matrix) != 0)
	{
		return (1);
	}
	if (close_file(inf_map->file) != 0)
	{
		return (1);
	}
	return (0);
}

int	valid_break(t_inf_map *inf_map)
{
	if (inf_map->row == 0)
	{
		return (-2);
	}
	if (inf_map->symbol[0] == '\0')
	{
		return (-2);
	}
	return (-1);
}

int	valid_symbol(t_inf_map *inf_map, char *buffer)
{
	int	i;

	i = 0;
	if (inf_map->row == 0)
	{
		return (-2);
	}
	while (i < 3)
	{
		if (inf_map->symbol[i] == '\0')
		{
			inf_map->symbol[i] = buffer[0];
			return (0);
		}
		else
		{
			i++;
		}
	}
	if (i == 3)
	{
		return (-2);
	}
	return (1);
}

int	read_info(t_inf_map *inf_map, char *buffer)
{
	if (buffer[0] >= 48 && buffer[0] <= 57 && inf_map->symbol[0] == '\0')
	{
		inf_map->row = inf_map->row * 10 + (buffer[0] - '0');
		return (0);
	}
	else if (buffer[0] == '\n')
	{
		return (valid_break(inf_map));
	}
	else
	{
		return (valid_symbol(inf_map, buffer));
	}
}
