/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstr_from_mapfile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:56:08 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/24 21:56:32 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (tmp == NULL)
			ft_error("Failed to malloc allocated.\n");
		str = tmp;
	}
	return (NULL);
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
