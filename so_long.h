/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:46:31 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/18 17:43:51 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

#include <stdio.h>	// delete

# define BUFFER_SIZE 42
# define EMPTY 0
# define WALL 1
# define ITEM 2
# define EXIT 3
# define PLAYER 4
# define IMG_BG "img/background.xpm"
# define IMG_WALL "img/sea.xpm"
# define IMG_ITEM "img/coin1.xpm"
# define IMG_EXIT "img/dragon.xpm"
# define IMG_PLAYER "img/player_front.xpm"
// school
# define ESC 53
# define UP 13
# define DOWN 2
# define RIGHT 1
# define LEFT 0

/* // home
# define ESC 65307
# define UP 'w'
# define DOWN 's'
# define RIGHT 'd'
# define LEFT 'a'
*/
typedef struct	s_player{
	int		x;
	int		y;
	int		count;
	int		leftover_item;
	bool	complete;
}				t_player;

typedef struct	s_data {
	void		*ptr;
	void		*win;
	void		*img;
	t_player	player;
}				t_data;

// map
char	**create_strs_map(char *mapfile);
char	*getstr_from_mapfile(char *mapfile, unsigned int *map_status);
void	check_count(unsigned int *map_status);
bool	check_char(char *str, unsigned int *map_status);
bool	is_rectanglar(char **map);
int		cal_width(char **map);
int		cal_height(char **map);

// draw
int		draw_map(char **map, t_data *mlx, t_player *player);
int		key_hook(int keycode, t_data *mlx, char **map, t_player *player);


// move
void	move_player(int keycode, t_data *mlx, char **map, t_player *player);

// error
void	ft_error(char *str);

#endif