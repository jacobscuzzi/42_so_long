/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 02:03:48 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/19 05:22:02 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
void	in_love(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/one_heart.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->gamer_pos->column,
		data->pxl * data->gamer_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/two_heart.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->gamer_pos->column,
		data->pxl * data->gamer_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/three_heart.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->gamer_pos->column,
		data->pxl * data->gamer_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/four_heart.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->gamer_pos->column,
		data->pxl * data->gamer_pos->row);
	mlx_destroy_image(data->mlx, data->img);
}

*/

void	draw_bowser(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
}

void	bowser_up(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser_jump.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	(data->bowser_pos->row)--;
	draw_window(data);
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser_jump.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	draw_bowser(data);
	draw_gamer(data);
	return ;
}

void	bowser_down(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser_jump.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	(data->bowser_pos->row)++;
	draw_window(data);
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser_jump.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	draw_bowser(data);
	draw_gamer(data);
	return ;
}

void	bowser_left(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser_left1.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	(data->bowser_pos->column)--;
	draw_window(data);
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser_left2.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	draw_bowser(data);
	draw_gamer(data);
	return ;
}

void	bowser_right(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser_right1.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	(data->bowser_pos->column)++;
	draw_window(data);
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./img/bowser_right2.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->img, data->pxl * data->bowser_pos->column,
		data->pxl * data->bowser_pos->row);
	mlx_destroy_image(data->mlx, data->img);
	draw_bowser(data);
	draw_gamer(data);
	return ;
}
