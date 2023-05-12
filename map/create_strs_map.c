/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strs_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:51:04 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/12 14:17:10 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>
char **create_strs_map(char *mapfile)
{
	char			*line = NULL;
 	unsigned int	map_status[5];
	char			**map = NULL;

	ft_bzero(map_status, sizeof(unsigned int) * 5);
	line = getstr_from_mapfile(mapfile, map_status);
	map = ft_split(line, '\n');
	if (map == NULL)
		ft_error("Failed to malloc allocated.\n");
	free(line);
	// 	// 辺には１だけ check_wall();
	// 	// back_trackで有効か判断
	// // error処理
	return (map);
}
