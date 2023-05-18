/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:00:59 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/17 05:44:53 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	process_player(t_data *mlx, t_player *player, size_t x, size_t y)
{
	int		width;
	int		height;

	width = 32;
	height = 32;
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_PLAYER, &width, &height);
	player->x = x;
	player->y = y;
}

int	draw_map(char **map, t_data *mlx, t_player *player)
{
	int		width;
	int		height;
	size_t	y;
	size_t	x;

	width = 32;
	height = 32;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0')
				mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_BG, &width, &height);
			else if (map[y][x] == '1')
				mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_WALL, &width, &height);
			else if (map[y][x] == 'C')
				mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_ITEM, &width, &height);
			else if (map[y][x] == 'E')
				mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_EXIT, &width, &height);
			else if (map[y][x] == 'P')
				process_player(mlx, player, x, y);
			if (mlx->img == NULL)
			{
				free(map);
				ft_error("mlx_new_image\n");
			}
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, x * 32, y * 32);
			mlx_destroy_image(mlx->ptr, mlx->img);
			x++;
		}
		y++;
	}
	return (0);
}
