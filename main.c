#include "mlx/mlx.h"

int main()
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "mlx 42");
	mlx_loop(mlx);
}
