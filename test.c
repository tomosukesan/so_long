#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	if (mlx_win == NULL)
	{
		ft_putstr_fd("Error:\n\tmlx_new_window\n", 2);
		exit(1);
	}
	width = 400;
	height = 380;
	img.img = mlx_xpm_file_to_image(mlx, "img/summer.xpm", &width, &height);
	// img.img = mlx_xpm_file_to_image(mlx, "img/watermelon.xpm", &width, &height);
	// img.img = mlx_xpm_file_to_image(mlx, "img/mountains.xpm", &width, &height);
	// img.img = mlx_xpm_file_to_image(mlx, "img/beetle.xpm", &width, &height);
	if (img.img == NULL)
	{
		ft_putstr_fd("Error:\n\tmlx_new_image\n", 2);
		exit(1);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
