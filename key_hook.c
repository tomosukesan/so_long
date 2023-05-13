/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:01:01 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/13 21:21:06 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *mlx, char **map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(map);
		exit(0);
	}
	return (0);
}
