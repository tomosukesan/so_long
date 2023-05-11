#include "so_long.h"

char	*get_mapfile(char *map_file)
{
	int		fd;
	char	*result;
	char	*line;

	fd = open(map_file, O_RDONLY);
	// openの失敗処理：あっているか確認
	if (fd == -1)
		ft_error("Failed to open file.\n");
	result = (char *)malloc(sizeof(char) * 1);
	if (result == NULL)
		ft_error("Failed to allocate memory.\n");
	result[0] = '\0';
	line = get_next_line(fd);
	while (line != NULL)
	{
		// 列の長さが違う場合の処理
		// 一行目の長さを取得して、それ以降の行の長さと比較
		result = ft_strjoin(result, line);
		free(line);
		line = get_next_line(fd);
	}
	// mapファイルの最後までgnlが読み込んだ判断は？ gnlの途中終了をどう判断する？
	free(line);
	close(fd);
	return (result);
}

int	main(int argc, char *argv[])
{
	// 現状、mapの構成は.ber拡張子ファイルに格納
	// 二次元配列で確保したい
	int				fd;
	char			*line;
	char			**map;
	unsigned int	*map_status;

	if (argc == 2)
		ft_error("Invalid argument.\n");
	line = get_mapfile(argv[1]);
	ft_bzero(map_status, 0);
	map = create_map(line, map_status);
	return (0);
}