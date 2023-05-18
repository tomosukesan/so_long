/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:46 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/18 19:30:06 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	click_close(t_data *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}

static void	*so_long(char **map)
{
	t_data		mlx;

	mlx.ptr = mlx_init();
	ft_bzero(&mlx.player, sizeof(t_player));
	if (mlx.ptr == NULL)
	{
		free(map);
		ft_error("mlx_init\n");
	}
	mlx.win = mlx_new_window(mlx.ptr, \
			cal_width(map), cal_height(map), "so_long");
	if (mlx.win == NULL)
	{
		free(map);
		ft_error("mlx_new_window\n");
	}
	draw_map(map, &mlx, &mlx.player);
	ft_putnbr_fd(mlx.player.leftover_item, 1);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, click_close, &mlx);	// 校舎用：提出
	// mlx_hook(mlx.win, 33, 1L << 17, click_close, &mlx); // 自宅用：テスト
	// 失敗した時はmapのfreeとwindowを閉じる処理を。
	// また、mlxのdestroyも必要
	mlx_loop(mlx.ptr);
	// mlx_loop_hook(mlx.ptr, draw_map, &mlx);
	return (mlx.ptr);
}

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc != 2)
		ft_error("Invalid argument.\n");
	map = create_strs_map(argv[1]);
	// mapを描画
	so_long(map);
	return (0);
}
