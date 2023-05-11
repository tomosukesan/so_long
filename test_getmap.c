#include "so_long.h"

static char *get_str_map(int fd, char *line, size_t width)
{
	char *result;

	result = ft_strjoin("", line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		// gnlの失敗は？ // 失敗も終了もNULLだからむずいな
		// でも終了はNULLかつ
		result = ft_strjoin(result, line);
		if (ft_strlen(line) != width)		// 最後の１回は許す？
			ft_error("Invalid map: It is not rectangular.\n");
	}
	// mapファイルの最後までgnlが読み込んだ判断は？ gnlの途中終了をどう判断する？
	free(line);		// line == NULLの時にwhile文を抜けている..NULLなのにfree要る？
	return (result);	// errorがあったらNULLで返す？その時はget_mapfileで
}

static char	*get_mapfile(char *map_file)
{
	int		fd;
	char	*line;
	char	*result;
	size_t	width;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_error("Failed to open file.\n");
	line = get_next_line(fd);
	// gnlの失敗は？
	width = ft_strlen(line);
	result = get_str_map(fd, line, width);
	close(fd);
	return (result);
}

static char **create_map(char *mapfile)
{
	char			**map;
 	unsigned int	*map_status;

	ft_bzero(map_status, 0);
	// 先ずはfileをstrに
		// 指定された５つの文字で、過不足なく構成されているか　→ map_statusを使用
	// strをstrsに -> ft_split(line, '\n');
		// 辺には１だけ check_wall();
		// back_trackで有効か判断
	// error処理

	return (map);
}


int	main(int argc, char *argv[])
{
	char			**map;

	if (argc == 2)
		ft_error("Invalid argument.\n");
	map = create_map(argv[1]);
	return (0);
}