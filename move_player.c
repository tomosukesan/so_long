/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:48:32 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/18 17:39:22 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static bool	check_wall(int keycode, char **map, t_player player)
// {
	
// }

void	move_player(int keycode, t_data *mlx, char **map, t_player *player)
{
	// UP: w, DOWN: s, RIGHT: d, LEFT: a
	// Playerが動くために
	// playerの位置を取得 > 押されたボタンの取得 > その方向には何があるか判定
		// wallは無理、itemなら数を加算、exitは無視orITEMを全て取っていたらゲーム終了
	// 動くことができたら、歩数の加算 > mapの配列を変更 > mapを一部描画
	// playerは構造体で把握？アイテムを何個拾ったか、歩数、現在地（pos_x, pos_y）
	int		width;
	int		height;

	width = 32;
	height = 32;
	ft_putnbr_fd(player->leftover_item, 1);
	// playerの位置確認
	if (keycode == UP)
	{
		// 上のmapを確認
		// 大丈夫ならmapを変更、mapを描画、++(player->count)、--(player->y)
			// アイテムかどうか、Exitかどうか
		if (map[player->y - 1][player->x] == WALL || \
			(player->leftover_item != 0 && map[player->y - 1][player->x] == EXIT))
			return ;
		else if (map[player->y - 1][player->x] == ITEM)
			--(player->leftover_item);
		else if (map[player->y - 1][player->x] == EXIT)
				player->complete = true;
		map[player->y][player->x] = EMPTY;
		map[player->y - 1][player->x] = PLAYER;
		//
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_BG, &width, &height);
		if (mlx->img == NULL)
		{
			free(map);
			ft_error("mlx_new_image\n");
		}
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, player->x * 32, player->y * 32);
		mlx_destroy_image(mlx->ptr, mlx->img);
		// same
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, IMG_PLAYER, &width, &height);
		if (mlx->img == NULL)
		{
			free(map);
			ft_error("mlx_new_image\n");
		}
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, player->x * 32, --(player->y) * 32);
		mlx_destroy_image(mlx->ptr, mlx->img);
		++(player->count);
	}
	else if (keycode == DOWN)
	{
		
	}
	else if (keycode == RIGHT)
	{
		
	}
	ft_putnbr_fd((int)player->count, 1);
	if (player->complete == true)
	{
		ft_putendl_fd("Completed!!", 1);
		exit (0);
	}
}