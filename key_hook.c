/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:01:01 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/18 15:37:35 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 自宅用
int	key_hook(int keycode, t_data *mlx, char **map, t_player *player)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(map);
		exit(0);
	}
	else if (keycode == 'a')	// else で済むかも
	{

	}
	else if (keycode == 's')
	{

	}
	else if (keycode == 'd')
	{

	}
	else if (keycode == 'w')
	{

	}
	return (0);
}


/* // 校舎用（提出用）
int	key_hook(int keycode, t_data *mlx, char **map)
{

	//if (keycode == 53)	// 校舎
	if (keycode == 65307)	// 自宅
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(map);
		exit(0);
	}
	return (0);
}
*/