/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:34:20 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/09 19:52:47 by jbaumfal         ###   ########.fr       */
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
int	so_long(t_data *data)
{
	draw_window(data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	mlx_loop(data->mlx);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	exit(0);
	return (0);
}
