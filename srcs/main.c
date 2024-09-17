/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:04:56 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/16 17:02:53 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int error_type)
{
	ft_printf("Error\n");
	if (error_type == 0)
		ft_putstr_fd("Number of Arguments Aint right ...\n", 2);
	if (error_type == 1)
		ft_putstr_fd("Mentioned file doesn't open\n", 2);
	if (error_type == 2)
		ft_putstr_fd("Map is not rectangular...\n", 2);
	if (error_type == 3)
		ft_putstr_fd("allocation failed\n", 2);
	if (error_type == 4)
		ft_putstr_fd("Map is missing Walls\n", 2);
	if (error_type == 5)
		ft_putstr_fd("Map has invalid, missing or double* characters\n", 2);
	if (error_type == 6)
		ft_putstr_fd("Map is not solvable\n", 2);
	if (error_type == 7)
			ft_putstr_fd("Error while reading Mapfile\n", 2);

}

void	free_data(t_data *data)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	free_all(data->map, *data->dim);
	free(data->gamer_pos);
	// if (data->addr)
	// 	free(data->addr);
	free(data->mlx);
	free(data->dim);
	free(data);
}
void	free_all(char **arr, t_coord dim)
{
	size_t	i;

	i = 0;
	while (i < dim.row)
		free(arr[i++]);
	free(arr);
}

/*
	typedef struct	s_data {
	char	**map;
	t_coord	*dim;
	t_coord	*gamer_pos;
	int		coins;
	void	*mlx;
	void	*mlx_win;
	char	*img;
	char	*addr;
	int		pxl;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	pos;
	char	*gamer_img;
	void	*textures[5];
	int		move_count;

}	t_data;

*/

t_data	*mapping(char *mapfile, int fd)
{
	t_coord	*dimension;
	t_data	*data;
	int		check;

	dimension = dimension_check(mapfile);
	ft_printf("Dimension Test run\n");
	if (!dimension)
		return (ft_error(2), NULL);
	ft_printf("Dimension Test succeed\n");
	data = new_game(dimension);
	ft_printf("Map struct creation\n");
	if (!data)
		return (free(dimension), ft_error(3), NULL);
	ft_printf("data struct succesful created\n");
	if (fill_map(data, fd) == 1)
		return (free_data(data), ft_error(7), NULL);
	ft_printf("Filled Map:\n");
	close(fd);
	if  (wall_check(data) == 0)
		return (free_data(data), ft_error(4), NULL);
	ft_printf("Walls Validated\n");
	check = map_check(data);
	if (check == 0)
		return (free_data(data), ft_error(5), NULL);
	ft_printf("Characters Validated\n");
	if (check == -1)
		return ( free_data(data), ft_error(6), NULL);
	ft_printf("Map Validated (Solvable)\n");
	return (data);
}

// void	print_map(t_data *data)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < data->dim->row)
// 		ft_printf("%s\n", data->map[i++]);
// 	return ;
// }


int	main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if (argc != 2)
		return (ft_error(0), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(1), 1);
	ft_printf("Map File opened\n");
	data = mapping(argv[1], fd);
	if (!data)
		return (1);
	so_long(data);
	return (0);
}
