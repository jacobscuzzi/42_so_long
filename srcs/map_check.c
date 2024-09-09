/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:47:58 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/09 06:08:42 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	wall_check(t_map *map)
{
	size_t	column;
	size_t	row;

	column = 0;
	row = 0;
	while (column < map->dim->column)
	{
		if (map->plan[0][column] != '1')
			return (0);
		if (map->plan[map->dim->row - 1][column] != '1')
			return (0);
		column++;
	}
	while (row < map->dim->row)
	{
		if (map->plan[row][0] != '1')
			return (0);
		if (map->plan[row][map->dim->column - 1] != '1')
			return (0);
		row++;
	}
	return (1);
}

int	char_check(t_map *map)
{
	size_t	row;
	size_t	column;

	row = 0;
	column = 0;
	while (row < map->dim->row)
	{
		while (column < map->dim->column)
		{
			if (ft_strchr("01EPC", map->plan[row][column]) == NULL)
				return (0);
			column++;
		}
		column = 0;
		row++;
	}
	return (1);
}

void	map_flood(char **map_clone, t_coord *dim,  size_t row, size_t column)
{
	if (!(ft_strchr("0PCE", map_clone[row][column])))
		return ;
	if (row >= dim->row)
		return ;
	if (row < 0)
		return ;
	if (column >= dim->column)
		return ;
	if (column < 0)
		return ;
	map_clone[row][column] = 'F';
	map_flood(map_clone, dim, row + 1, column);
	map_flood(map_clone, dim, row - 1, column);
	map_flood(map_clone, dim, row, column + 1);
	map_flood(map_clone, dim, row, column - 1);
	return ;
}

int map_solve(t_map *map, char **map_clone)
{
	map_flood(map_clone, map->dim, map->gamer_pos->row, map->gamer_pos->column);
	ft_printf("Flooded Map:\n");
	if (count_element(map, EXIT, map_clone) > 0 || count_element(map, 'C', map_clone) > 0)
		return (0);
	return (1);
}

int	map_check(t_map *map)
{
	int		exit;
	int		gamer_pos;
	char	**map_clone;

	exit = count_element(map, EXIT, map->plan);
	gamer_pos = count_element(map, GAMER, map->plan);
	map->coins = count_element(map, COIN, map->plan);
	if (char_check(map) == 0)
		return (0);
	ft_printf("no invalid characters\n");
	ft_printf("exits:%d, starts:%d, coins %d\n", exit, gamer_pos, map->coins);
	if (exit != 1 || gamer_pos != 1 || map->coins == 0)
	{
		ft_printf("character false\n");
		return (0);
	}
	*(map->gamer_pos) = find_element(map, GAMER);
	ft_printf("Gamer Pos: %d, %d\n", map->gamer_pos->row, map->gamer_pos->column);
	*(map->exit) = find_element(map, EXIT);
	ft_printf("no characters missing or double\n");
	map_clone = init_plan(map->dim);
	if (!map_clone)
		return (0);
	clone_plan(map_clone, map);
	if (map_solve(map, map_clone) == 0)
		return (-1);
	return (1);
}



