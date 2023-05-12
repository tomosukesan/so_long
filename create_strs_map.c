/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strs_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:51:04 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/11 23:51:32 by ttachi           ###   ########.fr       */
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
	maps = ft_split(line, '\n');
	if (maps == NULL)
		ft_error("Failed to malloc allocated.\n");
	free(line);
		// 辺には１だけ check_wall();
		// back_trackで有効か判断
	// error処理
	return (map);
}
