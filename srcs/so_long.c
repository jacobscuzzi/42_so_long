/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:34:20 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/06 01:29:26 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_data(t_data *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->mlx_win)
		free(data->mlx_win);
	free(data);
}


int	so_long(t_map *map)
{
	t_data	data;
	data.map = map;
	
	data.mlx = mlx_init();
	if(!data.mlx)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, (map->dim->column + 1) * BLOCK_SIZE, (map->dim->row + 1) * BLOCK_SIZE , "Lets play!");
	if(!data.mlx_win)
		return (free_data(&data), 1);
	data.move_count = 0;
	data.pxl = BLOCK_SIZE;
	data.pos.row = 0;
	data.pos.column = 0;
	data.gamer_img = "./img/gamer.xpm";
	draw_window(&data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
	mlx_destroy_display(data.mlx);
	exit(0);
	return (free_data(&data), 0);
}
