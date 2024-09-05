/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:18:08 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/06 01:44:51 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_wall(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/wall.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->pos.column,
		data->pxl * data->pos.row);
}

void	draw_empty(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/floor.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->pos.column,
		data->pxl * data->pos.row);
}

void	draw_coin(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/coin.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->pos.column,
		data->pxl * data->pos.row);
}

void	draw_gamer(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			data->gamer_img, &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->map->gamer_pos->column,
		data->pxl * data->map->gamer_pos->row);
}

void	draw_exit(t_data *data)
{
	if (data->map->coins == 0)
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./img/exit.xpm", &data->pxl, &data->pxl);
	else
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./img/exit.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->pos.column,
		data->pxl * data->pos.row);
}

void draw_floor(t_data *data)
{
    data->pos.row = 0;
    while ((data->pos.row) < (data->map->dim->row))
	{
		data->pos.column = 0;
		while ((data->pos.column) < (data->map->dim->column))
		{
			data->img = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", 
				&data->pxl, &data->pxl);
			mlx_put_image_to_window (data->mlx, data->mlx_win,
				data->img, data->pxl * data->pos.column,
				data->pxl * data->pos.row);
			data->pos.column++;
		}
		data->pos.row++;
	}
}


void draw_window(t_data *data)
{
	draw_floor(data);
	data->pos.row = 0;
	while ((data->pos.row) < (data->map->dim->row))
	{
		data->pos.column = 0;
		while ((data->pos.column) < (data->map->dim->column))
		{
			if (data->map->plan[data->pos.row][data->pos.column] == WALL)
				draw_wall(data);
			if (data->map->plan[data->pos.row][data->pos.column] == COIN)
				draw_coin(data);
			if (data->map->plan[data->pos.row][data->pos.column] == EXIT)
				draw_exit(data);
			data->pos.column++;
		}
		data->pos.row++;
	}
	draw_gamer(data);
	ft_printf("Movements: %d\n", data->move_count);
}   