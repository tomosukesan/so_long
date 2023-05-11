/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strs_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:51:04 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/11 21:46:51 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **create_strs_map(char *mapfile)
{
	char			*line;
 	unsigned int	map_status[5];
	char			**map;

	ft_bzero(map_status, 0);
	line = getstr_from_mapfile(mapfile, map_status);
	// OK先ずはfileをstrに
		// 指定された５つの文字で、過不足なく構成されているか　→ map_statusを使用
	// strをstrsに -> ft_split(line, '\n');
		// 辺には１だけ check_wall();
		// back_trackで有効か判断
	// error処理
	ft_putendl_fd(line, 1);
	map = NULL;
	return (map);
}
