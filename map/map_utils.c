/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:34:26 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/14 14:09:18 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	cal_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	// int maxを超える処理
	return (i * 32);
}

int	cal_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	// int maxを超える処理
	return (i * 32);
}
