/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:08:30 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/08/22 00:24:20 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_element(t_map *map, char c)
{
	size_t	row;
	size_t	column;
	int		counter;

	row = 0;
	column = 0;
	counter = 0;
	while (row < map->dim->row)
	{
		while (column < map->dim->column)
		{
			if (map->plan[row][column] == c)
				counter++;
			column++;
		}
		column = 0;
		row++;
	}
	return (counter);
}
t_coord	find_element(t_map *map, char c)
{
	size_t	row;
	size_t	column;

	row = 0;
	column = 0;
	while (row < map->dim->row)
	{
		while (column < map->dim->column)
		{
			if (map->plan[row][column] == c)
				return ((t_coord){row, column});
			column++;
		}
		column = 0;
		row++;
	}
	return ((t_coord){0, 0});
}
int		can_move(t_map *map, int direction)
{
	long	pos_row;
	long	pos_column;

	pos_row = (long)(map->gamer_pos->row);
	pos_column = (long)(map->gamer_pos->column);
	if (direction == UP)
		pos_row --;
	if (direction == DOWN)
		pos_row ++;
	if (direction == RIGHT)
		pos_column ++;
	if (direction == LEFT)
		pos_column --;
	if (pos_row < 0 || pos_column < 0)
		return (0);
	if (map->plan[pos_row][pos_column] == WALL)
		return (0);
	return (1);
}
