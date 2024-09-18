/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:34:20 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/17 21:43:32 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void end_game(t_data *data)
{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free_data(data);
		exit(1);
}
void	so_long(t_data *data)
{
	draw_window(data);
	draw_gamer(data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	mlx_loop(data->mlx);
	// mlx_destroy_window(data->mlx, data->mlx_win);
	// mlx_destroy_display(data->mlx);
	exit(0);
	return ;
}
