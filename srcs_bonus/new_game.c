/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:22:04 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/20 18:35:43 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

size_t	line_size(char *row)
{
	size_t	i;

	i = 0;
	while (row[i] != '\n' && row[i] != '\0')
		i++;
	return (i);
}

void	column_count(char *row, t_coord	*size)
{
	size->column = line_size(row);
	size->row = 1;
}

t_coord	*dimension_check(char	*mapfile)
{
	int		fd;
	t_coord	*size;
	char	*row;

	size = (t_coord *)malloc(sizeof(t_coord));
	if (!size)
		return (NULL);
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (close(fd), free(size), NULL);
	row = get_next_line(fd);
	if (!row)
		return (close(fd), free(size), NULL);
	column_count(row, size);
	free(row);
	row = get_next_line(fd);
	while (row != NULL)
	{
		if (line_size(row) != size->column)
			return (free(size), free(row), close(fd), NULL);
		size->row++;
		free(row);
		row = get_next_line(fd);
	}
	return (close(fd), free(row), size);
}

char	**init_map(t_coord *dim)
{
	char		**map;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(char *) * (dim->row));
	if (!map)
		return (NULL);
	while (i < dim->row)
	{
		map[i] = (char *)malloc(sizeof(char) * (dim->column));
		if (!map[i])
			return (free_all(map, *dim), NULL);
		i++;
	}
	return (map);
}

t_data	*new_game(t_coord *dimension)
{
	t_data *(data) = (t_data *)malloc(sizeof (t_data));
	if (!data)
		return (NULL);
	data->map = init_map(dimension);
	if (!(data->map))
		return (free_data(data), NULL);
	data->gamer_pos = (t_coord *)malloc(sizeof (t_coord));
	if (!(data->gamer_pos))
		return (NULL);
	data->bowser_pos = (t_coord *)malloc(sizeof (t_coord));
	if (!(data->bowser_pos))
		return (NULL);
	data->dim = dimension;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_data(data), NULL);
	data->mlx_win = mlx_new_window(data->mlx,
			(data->dim->column) * BLOCK_SIZE,
			(data->dim->row) * BLOCK_SIZE, "Lets play!");
	if (!data->mlx_win)
		return (free_data(data), NULL);
	data->move_count = 0;
	data->pxl = BLOCK_SIZE;
	data->pos.row = 0;
	return (data->pos.column = 0, data);
}
