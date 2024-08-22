/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:51:51 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/08/19 17:44:35 by jbaumfal         ###   ########.fr       */
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

