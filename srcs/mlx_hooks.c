/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:06:27 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/05 19:31:44 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	on_keypress(int keysim, t_data *data)
{
	size_t	*pos_row;
	size_t	*pos_column;
	
	if (keysim == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free_data(data);
		exit(1);
	}
	pos_row = &(data->map->gamer_pos->row);
	pos_column = &(data->map->gamer_pos->column);
	if (keysim == UP && can_move(data->map, UP) == 1)
		(*pos_row)--;
	if (keysim == DOWN && can_move(data->map, DOWN) == 1)
		(*pos_row)++;
	if (keysim == RIGHT && can_move(data->map, RIGHT) == 1)
		(*pos_column)++;
	if (keysim == LEFT && can_move(data->map, LEFT) == 1)
		(*pos_column)--;
	data->move_count++;
	printf("position: row: %zu, column: %zu\n", *pos_row, *pos_column);
	return (0);
}
