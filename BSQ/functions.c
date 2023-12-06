/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrentero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:22:39 by jrentero          #+#    #+#             */
/*   Updated: 2023/11/29 00:47:18 by jrentero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compares adjacent cells an returns minimum

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

void	r_sym(char **c_mtrx, int **n_mtrx, t_inf_map *inf_map, t_mx_sqr *mx_sqr)
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
			printf("%c", c_mtrx[i][j]);
			j++;
		}
		i++;
		printf("\n");
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
	free(inf_map);
	inf_map->file = NULL;
	inf_map->row = 0;
	inf_map->col = 0;
	inf_map->symbol[2] = 0;
	inf_map->symbol[1] = 0;
	inf_map->symbol[0] = 0;
}

void	free_mx_sqr(t_mx_sqr *mx_sqr)
{
	free(mx_sqr);
	mx_sqr->size = 0;
	mx_sqr->position[1] = 0;
	mx_sqr->position[0] = 0;
}

int	main(int argc, char **argv)
{
	int			i;
	int			**n_mtrx;
	char		**c_mtrx;
	t_inf_map	*inf_map;
	t_mx_sqr	*mx_sqr;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			inf_map = (t_inf_map *)malloc(24);
			inf_map->file = argv[i];
			if (valid_file(inf_map) != 0)
			{
				printf("%s\n", "map error");
				return (1);
			}
			n_mtrx = def_n_mtrx(inf_map);
			if (set_n_mtrx(inf_map, n_mtrx) != 0)
			{
				printf("%s\n", "map error");
				return (1);
			}
			mx_sqr = (t_mx_sqr *)malloc(24);
			cal_mx_sqr(mx_sqr, n_mtrx, inf_map);
			c_mtrx = def_c_mtrx(inf_map);
			r_sym(c_mtrx, n_mtrx, inf_map, mx_sqr);
			free_mx_sqr(mx_sqr);
			free_n_mtrx(n_mtrx, inf_map);
			print_c_mtrx(c_mtrx, inf_map);
			free_c_mtrx(c_mtrx, inf_map);
			free_inf_map(inf_map);
			i++;
		}
	}
	return (0);
}
