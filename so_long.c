/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:46 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/12 14:19:31 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*so_long(char **map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	ft_bzero(&img, sizeof(t_data));
	if (mlx_win == NULL)
	{
		free(map);
		ft_error("mlx_new_window\n");
	}
	draw_map(map, mlx, mlx_win, img);
	// 失敗した時はmapのfreeとwindowを閉じる処理を。
	return (mlx);
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
