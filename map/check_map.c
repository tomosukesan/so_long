/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 06:53:40 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/13 07:39:07 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_count(unsigned int *map_status)
{
	if (map_status[ITEM] == 0)
		ft_error("Invalid map. It is consist of no item.\n");
	else if (map_status[EXIT] != 1)
	{
		ft_putnbr_fd(map_status[EXIT], 1);
		ft_putchar_fd('\n', 1);
		ft_error("Invalid map about exit.\n");
	}
	else if (map_status[PLAYER] != 1)
		ft_error("Invalid map about player.\n");
}

bool	check_char(char *str, unsigned int *map_status)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
			map_status[EMPTY]++;
		else if (str[i] == '1')
			map_status[WALL]++;
		else if (str[i] == 'C')
			map_status[ITEM]++;
		else if (str[i] == 'E')
			map_status[EXIT]++;
		else if (str[i] == 'P')
			map_status[PLAYER]++;
		else if (str[i] == '\n')
			;
		else
			return (false);
		i++;
	}
	return (true);
}

bool	is_rectanglar(char **map)
{
	size_t	rule;
	size_t	comp;
	size_t	i;

	rule = ft_strlen(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		comp = ft_strlen(map[i]);
		if (rule != comp)
		{
			free(map);
			return (false);
		}
		i++;
	}
	return (true);
}
