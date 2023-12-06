/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrentero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:13:00 by jrentero          #+#    #+#             */
/*   Updated: 2023/11/29 18:28:02 by jrentero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	read_byte(int file, char *buffer)
{
	return read(file, buffer, 1);
}

int	open_file(char *file)
{
	int	flag_file;

	flag_file = open(file, O_RDONLY);
	if (flag_file == -1)
	{
		return (-1);
	}
	return (flag_file);
}

int	check_col(t_inf_map *inf_map, char *buffer, int *col_check)
{
	if (buffer[0] != '\n')
	{
		inf_map->col++;
	}
	else
	{
		if (inf_map->col == *col_check || *col_check == 0)
		{
			*col_check = inf_map->col;
			inf_map->col = 0;
		}
		else if (inf_map->col != *col_check)
		{
			return (1);
		}
	}
	return (0);
}

int	check_info(t_inf_map *inf_map)
{
	int		byte_read;
	char	buffer[1];
	int		col_check;
	int		flag;

	byte_read = 0;
	col_check = 0;
	flag = 0;
	while ((byte_read = read_byte(inf_map->file, buffer)) > 0)
	{
		if (flag >= 0)
		{
			flag = read_info(inf_map, buffer);
			if (flag == -2)
				return (1);
		}
		else
		{
			if (check_col(inf_map, buffer, &col_check) != 0)
				return (1);
		}
	}
	return (0);
}

int	set_n_matrix(t_inf_map *inf_map, int **n_matrix)
{
	char	buffer[1];
	int		i;
	int		j;
	int		byte_read;

	i = -1;
	j = 0;
	while ((byte_read = read_byte(inf_map->file, buffer)) > 0)
	{
		if (i == -1)
		{
			if (buffer[0] == '\n')
				i = 0;
		}
		else
		{
			if (buffer[0] == inf_map->symbol[0])
				n_matrix[i][j++] = 1;
			else if (buffer[0] == inf_map->symbol[1])
				n_matrix[i][j++] = 0;
			else if (buffer[0] == '\n')
			{
				i++;
				j = 0;
			}
		}
	}
	return (0);
}
