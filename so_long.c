/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:46 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/12 09:07:35 by ttachi           ###   ########.fr       */
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
	char	**map;

	if (argc != 2)
		ft_error("Invalid argument.\n");
	map = create_strs_map(argv[1]);
	// mapを描画

	return (0);
}
