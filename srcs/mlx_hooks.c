/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:06:27 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/10 19:55:03 by jbaumfal         ###   ########.fr       */
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
	}
	if (data->map[*row][*column] == EXIT)
	{
		if (data->coins == 0)
			end_game(data);
	}
}

int	on_keypress(int keysim, t_data *data)
{
	size_t	*pos_row;
	size_t	*pos_column;

	if (keysim == ESC)
	{
		on_destroy(data);
		return (0);
	}
	pos_row = &(data->gamer_pos->row);
	pos_column = &(data->gamer_pos->column);
	if (keysim == UP && can_move(data, UP) == 1)
		(*pos_row)--;
	if (keysim == DOWN && can_move(data, DOWN) == 1)
		(*pos_row)++;
	if (keysim == RIGHT && can_move(data, RIGHT) == 1)
		(*pos_column)++;
	if (keysim == LEFT && can_move(data, LEFT) == 1)
		(*pos_column)--;
	data->move_count++;
	printf("position: row: %zu, column: %zu\n", *pos_row, *pos_column);
	location_check(data, pos_row, pos_column);
	draw_window(data);
	return (0);
}
