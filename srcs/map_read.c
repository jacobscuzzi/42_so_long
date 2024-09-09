/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:51:51 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/09 19:40:59 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_data *data, int fd)
{
	char		*cache;
	size_t		column;
	size_t		row;

	column = 0;
	row = 0;
	while (row < data->dim->row)
	{
		cache = get_next_line(fd);
		while (column < data->dim->column)
		{
			data->map[row][column] = cache[column];
			column++;
		}
		data->map[row][column] = '\0';
		column = 0;
		row++;
		free(cache);
	}
	*data->gamer_pos = find_element(data, GAMER);
	ft_printf("map filled\n");
	return ;
}

void	clone_map(char **map_clone, t_data *data)
{
	size_t	i;
	size_t j;

	i = 0;
	while (i < data->dim->row)
	{
		j = 0;
		while (j < data->dim->column)
		{
			map_clone[i][j] = data->map[i][j];
			j++;
		}
		i++;
	}
}
