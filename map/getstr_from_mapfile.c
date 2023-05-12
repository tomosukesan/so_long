/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstr_from_mapfile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:56:08 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/12 13:43:32 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*finish_line(char *str, char *buf, ssize_t word_count)
{
	if (word_count == 0)
		free(buf);
	else if (word_count == -1)
	{
		free(buf);
		free(str);
		ft_error("Failed to read map file.\n");
	}
	return (str);
}

static char	*get_line(int fd)
{
	char	*str;
	char	*buf;
	char	*tmp;
	ssize_t	word_count;

	str = (char *)malloc(sizeof(char) * 1);
	if (str == NULL)
		ft_error("Failed to malloc allocated.\n");
	str[0] = '\0';
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		ft_error("Failed to malloc allocated.\n");
	while (1)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		word_count = read(fd, (void *)buf, BUFFER_SIZE);
		if (word_count == 0 || word_count == -1)
			return (finish_line(str, buf, word_count));
		tmp = ft_strjoin(str, buf);
		free(str);
		str = NULL;
		if (tmp == NULL)
			ft_error("Failed to malloc allocated.\n");
		str = tmp;
	}
	return (NULL);
}
static bool	check_char(char *str, unsigned int *map_status)
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

static void	check_count(unsigned int *map_status)
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

char	*getstr_from_mapfile(char *mapfile, unsigned int *map_status)
{
	int		fd;
	char	*str;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		ft_error("Failed to open file.\n");
	str = get_line(fd);
	if (str == NULL)
		ft_error("Failed to malloc allocated.\n");
	if (check_char(str, map_status) == false)
		ft_error("Invalid map. It is consist of Invalid character.\n");
	check_count(map_status);
	close(fd);
	return (str);
}
