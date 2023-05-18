/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:01:01 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/18 19:17:31 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *mlx, char **map, t_player *player)
{
	ft_putnbr_fd(player->leftover_item, 1);
	puts("");
	// printf("keycode: %d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(map);
		exit(0);
	}
	else if (keycode == LEFT || keycode == UP || keycode == DOWN || keycode == RIGHT)
		move_player(keycode, mlx, map, player);
	return (0);
}
