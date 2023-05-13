/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:00:59 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/13 20:45:42 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	draw_map(char **map, t_data *mlx)
{
	int		width;
	int		height;
	size_t	y;
	size_t	x;

	width = 400;
	height = 380;
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
				mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_PLAYER, &width, &height);
			if (mlx->img == NULL)
			{
				free(map);
				ft_error("mlx_new_image\n");
			}
			x++;
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, x * 40, y * 40);
			mlx_destroy_image(mlx->ptr, mlx->img);
		}
		y++;
	}

	// img.img = mlx_xpm_file_to_image(mlx, "img/watermelon.xpm", &width, &height);
	// img.img = mlx_xpm_file_to_image(mlx, "img/mountains.xpm", &width, &height);
	// img.img = mlx_xpm_file_to_image(mlx, "img/beetle.xpm", &width, &height);
}
