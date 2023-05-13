/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:46 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/13 19:26:10 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*so_long(char **map)
{
	t_data	mlx;

	//mlx_initは失敗するんだっけ？
	mlx.img = mlx_init();
	// windowの大きさ設定
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "so_long");
	// signal or eventを設定

	mlx_key_hook(mlx.win, key_hook, NULL);
	ft_bzero(mlx.img, sizeof(t_data));
	if (mlx.win == NULL)
	{
		free(map);
		ft_error("mlx_new_window\n");
	}
	draw_map(map, mlx.ptr, mlx.win, mlx.img);
	// 失敗した時はmapのfreeとwindowを閉じる処理を。
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
