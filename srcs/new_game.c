/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:22:04 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/10 20:02:49 by jbaumfal         ###   ########.fr       */
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

void	free_all(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**init_map(t_coord *dim)
{
	char		**map;
	size_t		i;

	ft_printf("Dimension %d * %d \n", dim->row, dim->column);
	i = 0;
	map = (char **)malloc(sizeof(char *) * (dim->column + 1));
	if (!map)
		return (NULL);
	while (i < dim->row)
	{
		map[i] = (char *)malloc(sizeof(char) * (dim->column + 1));
		if (!map[i])
			return (free_all(map), NULL);
		i++;
	}
	ft_printf("map allocated succesfully\n");
	return (map);
}

t_data	*new_game(t_coord *dimension)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof (t_data));
	if (!data)
		return (NULL);
	data->map = init_map(dimension);
	if (!(data->map))
		return (NULL);
	ft_printf("map stored in data succesfully\n");
	data->gamer_pos = (t_coord *)malloc(sizeof (t_coord));
	if (!(data->gamer_pos))
		return (NULL);
	data->dim = dimension;
	data->mlx = mlx_init();
	if(!data->mlx)
		return (NULL);
	data->mlx_win = mlx_new_window(data->mlx, (data->dim->column + 1) * BLOCK_SIZE, (data->dim->row + 1) * BLOCK_SIZE , "Lets play!");
	if(!data->mlx_win)
		return (free_data(data), NULL);
	data->move_count = 0;
	data->pxl = BLOCK_SIZE;
	data->pos.row = 0;
	data->pos.column = 0;
	data->gamer_img = "./img/gamer.xpm";
	ft_printf("data allocated succesfully\n");
	return (data);
}
