/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:00:59 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/12 11:48:07 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(char **map, void *mlx, void *mlx_win, t_data img)
{
	int		width;
	int		height;
	size_t	i;
	size_t	j;

	width = 400;
	height = 380;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' || map[i][j] != '\0')
		{
			if (map[i][j] == '0')
				img.img = mlx_xpm_file_to_image(mlx, IMG_BG, &width, &height);
			else if (map[i][j] == '1')
				img.img = mlx_xpm_file_to_image(mlx, IMG_WALL, &width, &height);
			else if (map[i][j] == 'C')
				img.img = mlx_xpm_file_to_image(mlx, IMG_ITME, &width, &height);
			else if (map[i][j] == 'E')
				img.img = mlx_xpm_file_to_image(mlx, IMG_EXIT, &width, &height);
			else if (map[i][j] == 'P')
				img.img = mlx_xpm_file_to_image(mlx, IMG_PLAYER, &width, &height);
			if (img.img == NULL)
			{
				free(map);
				ft_error("mlx_new_image\n");
			}
			j++;
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			mlx_loop(mlx);
		}
		i++;
	}
	// img.img = mlx_xpm_file_to_image(mlx, "img/watermelon.xpm", &width, &height);
	// img.img = mlx_xpm_file_to_image(mlx, "img/mountains.xpm", &width, &height);
	// img.img = mlx_xpm_file_to_image(mlx, "img/beetle.xpm", &width, &height);
}
