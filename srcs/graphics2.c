/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:35:35 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/11 21:32:04 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_gamer(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			data->gamer_img, &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->gamer_pos->column,
		data->pxl * data->gamer_pos->row);
	mlx_destroy_image(data->mlx, data->img);
}

void	gamer_up(t_data *data)
{
	data->gamer_img = "./img/gamer_jump.xpm";
	draw_gamer(data);
	draw_gamer(data);
	draw_gamer(data);
	(data->gamer_pos->row)--;
	draw_window(data);
	data->gamer_img = "./img/gamer_jump.xpm";
	draw_gamer(data);
	draw_gamer(data);
	draw_gamer(data);
	data->gamer_img = "./img/gamer.xpm";
	draw_gamer(data);
	return ;
}

void	gamer_down(t_data *data)
{
	data->gamer_img = "./img/gamer_jump1.xpm";
	draw_gamer(data);
	(data->gamer_pos->row)++;
	draw_window(data);
	data->gamer_img = "./img/gamer_land.xpm";
	draw_gamer(data);
	data->gamer_img = "./img/gamer.xpm";
	draw_gamer(data);
	return ;
}

void	gamer_left(t_data *data)
{
	data->gamer_img = "./img/gamer_left1.xpm";
	draw_gamer(data);
	(data->gamer_pos->column)--;
	draw_window(data);
	data->gamer_img = "./img/gamer_left2.xpm";
	draw_gamer(data);
	return ;
}
void	gamer_right(t_data *data)
{
	data->gamer_img = "./img/gamer_right1.xpm";
	draw_gamer(data);
	(data->gamer_pos->column)++;
	draw_window(data);
	data->gamer_img = "./img/gamer_right2.xpm";
	draw_gamer(data);
	data->gamer_img = "./img/gamer.xpm";
	draw_gamer(data);
	return ;
}

