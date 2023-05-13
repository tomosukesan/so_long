/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:46:31 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/13 21:24:53 by ttachi           ###   ########.fr       */
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

#include <stdio.h>

# define BUFFER_SIZE 42
# define EMPTY 0
# define WALL 1
# define ITEM 2
# define EXIT 3
# define PLAYER 4
# define IMG_BG "img/mountains.xpm"
# define IMG_WALL "img/mountains.xpm"
# define IMG_ITEM "img/watermelon.xpm"
# define IMG_EXIT "img/summer.xpm"
# define IMG_PLAYER "img/beetle.xpm"

typedef struct	s_data {
	void	*ptr;
	void	*win;
	void	*img;
}				t_data;

char	**create_strs_map(char *mapfile);
char	*getstr_from_mapfile(char *mapfile, unsigned int *map_status);
void	check_count(unsigned int *map_status);
bool	check_char(char *str, unsigned int *map_status);
bool	is_rectanglar(char **map);
int		key_hook(int keycode, t_data *mlx, char **map);

void	draw_map(char **map, t_data *mlx);
void	ft_error(char *str);

#endif