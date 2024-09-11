/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:58:01 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/09/11 21:16:40 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>


# define BLOCK_SIZE 50
# define NBR_TEXTURES 14

# define GAMER 'P'
# define EXIT 'E'
# define COIN 'C'
# define WALL '1'
# define EMPTY '0'

// KEY CODES

# define ESC 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define RESTART 114


typedef struct coordinate
{
	size_t	row;
	size_t	column;
}	t_coord;


typedef struct s_data
{
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
	void	*textures[NBR_TEXTURES];
	int		move_count;

}	t_data;


void	ft_error(int error_type);
void	print_map(t_data *data);

size_t	line_size(char *line);
t_coord	*dimension_check(char	*mapfile);
char	**init_map(t_coord *dim);
t_data	*new_game(t_coord *dimension);

void	fill_map(t_data *data, int fd);
void	clone_map(char **map_clone, t_data *data);

int		map_check(t_data *data);
int		wall_check(t_data *data);
int		char_check(t_data *data);
int		map_solve(t_data *data, char **map_clone);

int	count_element(t_data *data, char c, char **map);
t_coord	find_element(t_data *data, char c);
int		can_move(t_data *data, int direction);

int		on_destroy(t_data *data);
int		on_keypress(int keysymm, t_data *data);

int		so_long(t_data *data);
void	free_data(t_data *data);
void	end_game(t_data *data);


void	draw_window(t_data *data);

void	draw_gamer(t_data *data);
void	gamer_up(t_data *data);
void	gamer_down(t_data *data);
void	gamer_left(t_data *data);
void	gamer_right(t_data *data);

#endif
