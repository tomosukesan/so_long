/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:48:32 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/24 05:58:03 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_img(t_data *mlx, char **map, t_player *player, int dir[4])
{
	int	size;
	int	x;
	int	y;

	size = 32;
	x = dir[2] + dir[3];
	y = dir[0] + dir[1];
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_BG, &size, &size);
	if (mlx->img == NULL)
	{
		free_map(map);
		ft_error("mlx_new_image\n");
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, \
							player->x * 32, player->y * 32);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_PLAYER, &size, &size);
	if (mlx->img == NULL)
	{
		free_map(map);
		ft_error("mlx_new_image\n");
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, \
							(player->x + x) * 32, (player->y + y) * 32);
	mlx_destroy_image(mlx->ptr, mlx->img);
}

void	move_player(t_data *mlx, char **map, t_player *player, int direction[4])
{
	int	x;
	int	y;

	x = direction[2] + direction[3];
	y = direction[0] + direction[1];
	if (map[player->y + y][player->x + x] == WALL || \
	(player->leftover_item != 0 && map[player->y + y][player->x + x] == EXIT))
		return ;
	else if (map[player->y + y][player->x + x] == ITEM)
		--(player->leftover_item);
	else if (map[player->y + y][player->x + x] == EXIT)
			player->complete = true;
	map[player->y][player->x] = EMPTY;
	map[player->y + y][player->x + x] = PLAYER;
	change_img(mlx, map, player, direction);
	++(player->count);
	player->x += x;
	player->y += y;
	ft_putnbr_fd(player->count, 1);
	ft_putchar_fd(' ', 1);
	if (player->complete == true)
	{
		ft_putendl_fd("Completed!!", 1);
		exit (0);
	}
}
