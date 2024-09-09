/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:51:51 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/09 05:52:23 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_plan(t_map *map, int fd)
{
	char		*cache;
	size_t		column;
	size_t		row;

	column = 0;
	row = 0;
	while (row < map->dim->row)
	{
		cache = get_next_line(fd);
		while (column < map->dim->column)
		{
			map->plan[row][column] = cache[column];
			column++;
		}
		map->plan[row][column] = '\0';
		column = 0;
		row++;
		free(cache);
	}
	ft_printf("Plan filled\n");
	return ;
}

void	clone_plan(char **map_clone, t_map *map)
{
	size_t	i;
	size_t j;

	i = 0;
	while (i < map->dim->row)
	{
		j = 0;
		while (j < map->dim->column)
		{
			map_clone[i][j] = map->plan[i][j];
			j++;
		}
		i++;
	}
}
