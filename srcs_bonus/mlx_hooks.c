/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:06:27 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/20 20:26:56 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free_data(data);
	exit(1);
	return (0);
}

void	location_check(t_data *data, size_t *row, size_t *column, t_coord last)
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
		{
			ft_printf("YIPPIEH!!! MARIO MADE IT!!!!\n");
			end_game(data);
		}
	}
	if (*row == data->bowser_pos->row && *column == data->bowser_pos->column)
	{
		ft_printf("OUUUCCHHHH!!! MARIO GOT KILLED!!!!\n");
		end_game(data);
	}
	if (*row == last.row && *column == last.column)
	{
		ft_printf("OUUUCCHHHH!!! YOU BUMBED IN TO BOWSER!!!!\n");
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

void	bowser_moves(t_data *data, size_t row, size_t col)
{
	if (row > data->gamer_pos->row && bowser_can(data, UP))
		bowser_up(data);
	else if (col > data->gamer_pos->column && bowser_can(data, LEFT))
		bowser_left(data);
	else if (col < data->gamer_pos->column && bowser_can(data, RIGHT))
		bowser_right(data);
	else if (row < data->gamer_pos->column && bowser_can(data, DOWN))
		bowser_down(data);
	else if (bowser_can(data, DOWN))
		bowser_down(data);
	else if (bowser_can(data, RIGHT))
		bowser_right(data);
	else if (bowser_can(data, LEFT))
		bowser_left(data);
	else if (bowser_can(data, UP))
		bowser_up(data);
	return ;
}

int	on_keypress(int keysim, t_data *data)
{
	t_coord	last;

	last = *data->bowser_pos;
	bowser_moves(data, data->bowser_pos->row, data->bowser_pos->column);
	if (keysim == ESC)
		return (on_destroy(data), 0);
	if (keysim == UP && can_move(data, UP) == 1)
		gamer_moves(data, UP);
	if (keysim == DOWN && can_move(data, DOWN) == 1)
		gamer_moves(data, DOWN);
	if (keysim == RIGHT && can_move(data, RIGHT) == 1)
		gamer_moves(data, RIGHT);
	if (keysim == LEFT && can_move(data, LEFT) == 1)
		gamer_moves(data, LEFT);
	data->move_count++;
	draw_bowser(data);
	location_check(data, &data->gamer_pos->row, &data->gamer_pos->column, last);
	return (0);
}
