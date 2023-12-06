/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrentero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:57:47 by jrentero          #+#    #+#             */
/*   Updated: 2023/11/29 16:13:07 by jrentero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <fcntl.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_inf_map
{
	int		file;
	int		row;
	int		col;
	char	symbol[3];
}	t_inf_map;

typedef struct s_mx_sqr
{
	int	size;
	int	position[2];
}	t_mx_sqr;

int		ft_min(int x, int y, int z);
int		open_file(char *file);
int		close_file(int file);
int		read_info(t_inf_map *inf_map, char *buffer);
int		check_info(t_inf_map *inf_map);
int		**def_n_mtrx(t_inf_map *inf_map);
int		set_n_matrix(t_inf_map *inf_map, int **n_matrix);
void	cal_mx_sqr(t_mx_sqr *mx_sqr, int **n_mtrx, t_inf_map *inf_map);
char	**def_c_mtrx(t_inf_map *inf_map);
void	print_mx_sqr(char **c_mtrx, t_mx_sqr *mx_sqr, t_inf_map *inf_map);
void	sym(char **c_mtrx, int **n_mtrx, t_inf_map *inf_map, t_mx_sqr *mx_sqr);
void	print_c_mtrx(char **c_mtrx, t_inf_map *inf_map);
void	free_n_mtrx(int **n_mtrx, t_inf_map *inf_map);
void	free_c_mtrx(char **c_mtrx, t_inf_map *inf_map);
void	free_inf_map(t_inf_map *inf_map);
void	free_mx_sqr(t_mx_sqr *mx_sqr);
int		valid_file(char *name, t_inf_map *inf_map);
int		load_map(char *name, int **n_matrix, t_inf_map *inf_map);

#endif
