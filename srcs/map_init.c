/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:22:04 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/08/21 19:59:03 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	line_size(char *row)
{
	size_t	i;

	i = 0;
	while(row[i] != '\n' && row[i] != '\0')
		i++;
	return (i);
}

t_coord *dimension_check(char	*mapfile)
{
	int		fd;
	t_coord	*size;
	char	*row;

	size = (t_coord *)malloc(sizeof(t_coord));
	if (!size)
		return (NULL);
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (NULL);
	row = get_next_line(fd);
	if (!row)
		return (free(size), NULL);
	size->column = line_size(row);
	size->row = 1;
	free(row);
	row = get_next_line(fd);
	while (row != NULL)
	{
		if (line_size(row) != size->column)
			return (free(size),free(row), NULL);
		size->row++;
		free(row);
		row = get_next_line(fd);
	}
	close(fd);
	free(row);
	return (size);
}

char	**init_plan(t_coord *dim)
{
	char		**plan;
	size_t		i;

	ft_printf("Dimension %d * %d \n", dim->row, dim->column);
	i = 0;
	plan = (char **)malloc(sizeof(char *) * (dim->column + 1));
	if (!plan)
		return (NULL);
	ft_printf("plan allocated succesfully\n");
	while (i < dim->row)
	{
		plan[i] = (char *)malloc(sizeof(char) * (dim->column + 1));
		if (!plan[i])
			return (NULL);
		i++;
	}
	return (plan);
}

t_map	*new_map(t_coord *dimension)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof (t_map));
	if (!map)
		return (NULL);
	map->plan = init_plan(dimension);
	if (!(map->plan))
		return (NULL);
	map->gamer_pos = (t_coord *)malloc(sizeof (t_coord));
	if (!(map->gamer_pos))
		return (NULL);
	map->exit = (t_coord *)malloc(sizeof (t_coord));
	if (!(map->exit))
		return (NULL);
	map->dim = dimension;
	return (map);
}
