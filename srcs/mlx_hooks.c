/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:06:27 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/16 11:04:01 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free_data(data);
	exit(1);
	return (0);
}



void	location_check(t_data *data, size_t *row, size_t *column)
{
	if (data->map[*row][*column] == COIN)
	{
		data->map[*row][*column] = EMPTY;
		data->coins--;
		draw_gamer(data);
	}
	if (data->map[*row][*column] == EXIT)
	{
		if (data->coins == 0)
			end_game(data);
	}
}

void	gamer_moves(t_data *data, int direction )
{
	if (direction == UP)
		gamer_up(data);
	if (direction == DOWN)
		gamer_down(data);
	if (direction == RIGHT)
		gamer_right(data);
	if (direction == LEFT)
		gamer_left(data);
}

int	on_keypress(int keysim, t_data *data)
{
	if (keysim == ESC)
		return (on_destroy(data), 0);
	if (keysim == UP && can_move(data, UP) == 1)
		gamer_moves(data ,UP);
	if (keysim == DOWN && can_move(data, DOWN) == 1)
		gamer_moves(data, DOWN);
	if (keysim == RIGHT && can_move(data, RIGHT) == 1)
		gamer_moves(data , RIGHT);
	if (keysim == LEFT && can_move(data, LEFT) == 1)
		gamer_moves(data , LEFT);
	data->move_count++;
	location_check(data, &data->gamer_pos->row, &data->gamer_pos->column);
	draw_window(data);
	draw_gamer(data);
	return (0);
}
