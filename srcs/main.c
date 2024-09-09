/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:04:56 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/06 06:38:09 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int error_type)
{
	ft_printf("Error\n");
	if (error_type == 0)
		ft_putstr_fd("Number of Arguments Aint right ...\n", 2);
	if (error_type == 1)
		ft_putstr_fd("Mentioned file doesn't open\n", 2);
	if (error_type == 2)
		ft_putstr_fd("Map is not rectangular...\n", 2);
	if (error_type == 3)
		ft_putstr_fd("allocation failed\n", 2);
	if (error_type == 4)
		ft_putstr_fd("Map is missing Walls\n", 2);
	if (error_type == 5)
		ft_putstr_fd("Map has invalid, missing or double* characters\n", 2);
	if (error_type == 6)
		ft_putstr_fd("Map is not solvable\n", 2);
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->dim->row)
		free(map->plan[i++]);
	free(map->plan);
	if (map->gamer_pos != NULL)
		free(map->gamer_pos);
	if (map->exit != NULL)
		free(map->exit);
	free(map);
}

t_map	*mapping(char *mapfile, int	fd)
{
	t_coord	*dimension;
	t_map	*map;
	int		check;

	dimension = dimension_check(mapfile);
	ft_printf("Dimension Test run\n");
	if (!dimension)
		return (ft_error(2), NULL);
	ft_printf("Dimension Test succeed\n");
	map = new_map(dimension);
	ft_printf("Map struct creation\n");
	if (!map)
		return (free(dimension), ft_error(3), NULL);
	ft_printf("Map struct succesful created\n");
	fill_plan(map, fd);
	ft_printf("Filled Map:\n");
	print_map(map);
	close(fd);
	if  (wall_check(map) == 0)
		return (free_map(map), ft_error(4), NULL);
	ft_printf("Walls Validated\n");
	check = map_check(map);
	if (check == 0)
		return (free_map(map), ft_error(5), NULL);
	ft_printf("Characters Validated\n");
	if (check == -1)
		return ( free_map(map), ft_error(6), NULL);
	ft_printf("Map Validated (Solvable)\n");
	return (map);
}

void print_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->dim->row)
		ft_printf("%s\n", map->plan[i++]);
	return ;
}


int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		return (ft_error(0), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(1), 1);
	ft_printf("Map File opened\n");
	map = mapping(argv[1], fd);
	if (!map)
		return (1);
	
	if (so_long(map) == 1)
		return (1);
	return (0);
}
