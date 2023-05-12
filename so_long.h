/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:46:31 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/12 11:46:54 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <mlx.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 42
# define EMPTY 0
# define WALL 1
# define ITEM 2
# define EXIT 3
# define PLAYER 4
# define IMG_BG ""
# define IMG_WALL ""
# define IMG_ITME ""
# define IMG_EXIT ""
# define IMG_PLAYER ""

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

char	**create_strs_map(char *mapfile);
char	*getstr_from_mapfile(char *mapfile, unsigned int map_status[5]);
void	draw_map(char **map, void *mlx, void *mlx_win, t_data img);
void	ft_error(char *str);

#endif