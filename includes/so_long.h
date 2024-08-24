/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:58:01 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/08/24 12:01:05 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>


# define BLOCK_SIZE 32

# define GAMER 'P'
# define EXIT 'E'
# define COIN 'C'
# define WALL '1'
# define EMPTY '0'

// KEY CODES

# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define RESTART 114

typedef struct game_pixel
{
	int		x;
	int		y;
	char	type;
	char	status;
}	t_pixel;

typedef struct coordinate
{
	size_t	row;
	size_t	column;
}	t_coord;

typedef struct game_map
{
	char	**plan;
	t_coord	*exit;
	t_coord	*dim;
	t_coord	*gamer_pos;
}	t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
	void	*textures[5];
	void	*mlx;
	void	*mlx_win;
}	t_data;


void	ft_error(int error_type);
void	print_map(t_map *map);

size_t	line_size(char *line);
t_coord	*dimension_check(char	*mapfile);
char	**init_plan(t_coord *dim);
t_map	*new_map(t_coord *dimension);

void	fill_plan(t_map *map, int fd);

int		map_check(t_map *map);
int		wall_check(t_map *map);
int		char_check(t_map *map);
int		map_solve(t_map *maps);

int		count_element(t_map *map, char c);
t_coord	find_element(t_map *map, char c);
int		can_move(t_map *map, int direction);


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	on_destroy(t_data *data);
int	on_keypress(int keysymm, t_data *data);

int	so_long(t_map *map);
void	free_data(t_data *data);
#endif
