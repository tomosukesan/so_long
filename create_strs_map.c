/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strs_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:51:04 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/24 22:05:25 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_wall(char **map)
{
	ssize_t	x;
	ssize_t	y;
	ssize_t	height;

	x = -1;
	y = -1;
	height = cal_height(map);
	while (map[0][++x] != '\0')
		if (map[0][x] != WALL)
			return (false);
	while (++y < height)
		if (map[y][x - 1] != WALL)
			return (false);
	while (--x > -1)
		if (map[y - 1][x] != WALL)
			return (false);
	while (--y < -1)
		if (map[y][0] != WALL)
			return (false);
	return (true);
}

char	**create_strs_map(char *mapfile)
{
	char			*line;
	unsigned int	map_status[5];
	char			**map;

	ft_bzero(map_status, sizeof(unsigned int) * 5);
	line = getstr_from_mapfile(mapfile, map_status);
	map = ft_split(line, '\n');
	if (map == NULL)
		ft_error("Failed to malloc allocated at ft_split.\n");
	free(line);
	if (is_rectanglar(map) == false)
		ft_error("Invalid map. It is not rectanglar.\n");
	if (check_wall(map) == false)
		ft_error("Invalid map. It is not surrounded by walls.\n");
	// back_trackで有効か判断：player->x, player->yが全てのITEMをとってEXITにたどり着けるか
	// error処理
	return (map);
}
