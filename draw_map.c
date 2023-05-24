/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:00:59 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/24 21:50:32 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_img(t_data *mlx, char **map, int y, int x)
{
	int		size;

	size = 32;
	if (map[y][x] == '0')
		return (mlx_xpm_file_to_image(mlx->ptr, IMG_BG, &size, &size));
	else if (map[y][x] == '1')
		return (mlx_xpm_file_to_image(mlx->ptr, IMG_WALL, &size, &size));
	else if (map[y][x] == 'C')
	{
		++(mlx->player->leftover_item);
		return (mlx_xpm_file_to_image(mlx->ptr, IMG_ITEM, &size, &size));
	}
	else if (map[y][x] == 'E')
		return (mlx_xpm_file_to_image(mlx->ptr, IMG_EXIT, &size, &size));
	else if (map[y][x] == 'P')
	{
		mlx->player->x = x;
		mlx->player->y = y;
		return (mlx_xpm_file_to_image(mlx->ptr, IMG_PLAYER, &size, &size));
	}
	return (NULL);
}

int	draw_map(t_data *mlx, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			mlx->img = get_img(mlx, map, y, x);
			if (mlx->img == NULL)
			{
				free_map(map);
				ft_error("mlx_new_image\n");
			}
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, \
														x * 32, y * 32);
			mlx_destroy_image(mlx->ptr, mlx->img);
			x++;
		}
		y++;
	}
	return (0);
}
