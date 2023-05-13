/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:46 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/13 21:27:24 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	click_close(t_data *mlx)
{
	puts("aaa");
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}

static void	*so_long(char **map)
{
	t_data	mlx;

	//mlx_initは失敗するんだっけ？
	mlx.ptr = mlx_init();
	// windowの大きさ設定
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "so_long");
	if (mlx.win == NULL)
	{
		free(map);
		ft_error("mlx_new_window\n");
	}
	// signal or eventを設定
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 33, 1L << 17, click_close, &mlx);
	draw_map(map, &mlx);
	// 失敗した時はmapのfreeとwindowを閉じる処理を。
	mlx_loop(mlx.ptr);
	return (mlx.ptr);
}

int	main(int argc, char *argv[])
{
	char	**map = NULL;

	if (argc != 2)
		ft_error("Invalid argument.\n");
	map = create_strs_map(argv[1]);
	// mapを描画
	so_long(map);
	return (0);
}
