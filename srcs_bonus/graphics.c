/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:18:08 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/19 23:34:20 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_wall(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/wall.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->pos.column,
		data->pxl * data->pos.row);
	mlx_destroy_image(data->mlx, data->img);
}

void	draw_floor(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/floor.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->pos.column,
		data->pxl * data->pos.row);
	mlx_destroy_image(data->mlx, data->img);
}

void	draw_coin(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/coin.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->pos.column,
		data->pxl * data->pos.row);
	mlx_destroy_image(data->mlx, data->img);
}

void	draw_exit(t_data *data)
{
	if (data->coins == 0)
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./img/peach_exit.xpm", &data->pxl, &data->pxl);
	else
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./img/closed_exit.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->pos.column,
		data->pxl * data->pos.row);
	mlx_destroy_image(data->mlx, data->img);
}

void	draw_window(t_data *data)
{
	data->pos.row = 0;
	while ((data->pos.row) < (data->dim->row))
	{
		data->pos.column = 0;
		while ((data->pos.column) < (data->dim->column))
		{
			if (data->map[data->pos.row][data->pos.column] == WALL)
				draw_wall(data);
			else if (data->map[data->pos.row][data->pos.column] == COIN)
			{
				draw_floor(data);
				draw_coin(data);
			}
			else if (data->map[data->pos.row][data->pos.column] == EXIT)
			{
				draw_floor(data);
				draw_exit(data);
			}
			else
				draw_floor(data);
			data->pos.column++;
		}
		data->pos.row++;
	}
	draw_score(data);
}
