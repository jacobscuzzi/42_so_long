/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:34:20 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/08/21 23:25:23 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	so_long(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*data;

	data = malloc(sizeof(t_data));
	(void)map;
	mlx = mlx_init();
	if(!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, map->dim->column * BLOCK_SIZE,map->dim->row * BLOCK_SIZE , "Lets play!");
	if(!mlx)
		return (1);
	mlx_hook(mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
