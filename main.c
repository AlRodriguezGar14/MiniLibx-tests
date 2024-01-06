#include "mlx/mlx.h"
#include <stdio.h>

#define ESC 53

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct	s_vars
{
	void	*mlx;
	void	*window;
}	t_vars;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel * 8));
	*(unsigned int*)dst = color;
}

void	paint_lines(t_data *img, int x, int y, int color)
{
	my_mlx_pixel_put(img, x, y, color);
}

int	paint(int x, int y, t_vars *vars)
{
	t_data	img;
	img.img = mlx_new_image(vars->mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img,
								&img.bits_per_pixel,
								&img.line_length,
								&img.endian);
		
		paint_lines(&img, x, y, 0x000ff0ff);
		mlx_put_image_to_window(vars->mlx, vars->window, img.img, 0, 0);

	return (0);
}

int	use_key(int keycode, t_vars *vars)
{
	if (keycode != 53)
		printf("Hello key %d\n", keycode);
	else
		mlx_destroy_window(vars->mlx, vars->window);
	return (0);
}

int	use_mouse(int keycode, t_vars *vars)
{
	if (keycode == 1)
		printf("Left click!!\n");
	if (keycode == 2)
		printf("Right click!!\n");
	if (keycode == 4)
		printf("Scroll, scroll, scroll up\n");
	if (keycode == 5)
		printf("Scroll, scroll, scroll down\n");

	return (0);
}

int mouse_pos(int x, int y, t_vars *vars)
{
	printf("mouse position:\n\tx: %d\n\ty: %d\n", x, y);
	return (0);
}

int main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 500, 500, "mlx 42");
	

	// mlx_hook(vars.window, 6, 0, paint, &vars);
	mlx_key_hook(vars.window, use_key, &vars);
	mlx_mouse_hook(vars.window, use_mouse, &vars);
	mlx_hook(vars.window, 6, 0, mouse_pos, &vars);
	mlx_loop(vars.mlx);
}
