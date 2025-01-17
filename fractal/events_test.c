

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close_win(int keycode, t_vars *vars)
{
    (void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx);
}