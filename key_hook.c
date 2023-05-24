/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:01:01 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/24 21:57:55 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *mlx)
{
	int	direction[4];

	ft_bzero(direction, sizeof(int) * 4);
	if (keycode == ESC)
	{
		if (mlx->ptr == NULL)
			mlx_destroy_window(mlx->ptr, mlx->win);
		free_map(mlx->map);
		exit(0);
	}
	if (keycode == UP)
		direction[0] = -1;
	else if (keycode == DOWN)
		direction[1] = 1;
	else if (keycode == LEFT)
		direction[2] = -1;
	else if (keycode == RIGHT)
		direction[3] = 1;
	else
		return (0);
	move_player(mlx, mlx->map, mlx->player, direction);
	return (0);
}
