/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:48:32 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/18 15:37:42 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int keycode, t_data *mlx, char **map, t_player *player)
{
	// UP: w, DOWN: s, RIGHT: d, LEFT: a
	// Playerが動くために
	// playerの位置を取得 > 押されたボタンの取得 > その方向には何があるか判定
		// wallは無理、itemなら数を加算、exitは無視orITEMを全て取っていたらゲーム終了
	// 動くことができたら、歩数の加算 > mapの配列を変更 > mapを一部描画
	// playerは構造体で把握？アイテムを何個拾ったか、歩数、現在地（pos_x, pos_y）

}