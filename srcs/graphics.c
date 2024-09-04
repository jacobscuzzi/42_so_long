/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:18:08 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/04 23:27:52 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void draw_floor(t_data *data)
{
    data->pos->row = 0;
    //code kopiert muss noch angepasst werden an eigenen data Strukt
    while ((data->pos->row) < (data->map->dim->row))
	{
		data->pos->column = 0;
		while ((data->pos->column) < (data->map->dim->column))
		{
			game->file = mlx_xpm_file_to_image(game->mlx,
					"./img/floor.xpm", &game->pxl, &game->pxl);
			mlx_put_image_to_window (game->mlx, game->mlx_win,
				game->file, game->pxl * data->pos->column,
				game->pxl * game->y);
			data->pos->column++;
		}
		game->y++;
	}
}
}


void draw_window(t_map *map)
{
}