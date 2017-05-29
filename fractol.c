/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:00:25 by dzui              #+#    #+#             */
/*   Updated: 2017/02/22 16:00:27 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_controls(t_env *world)
{
	char *numbers;

	numbers = ft_itoa(world->iter);
	numbers = ft_strjoin("Iterations: ", numbers);
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 60, 0x00FFFFFF, "Fletches to move fractal");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 50, 0x00FFFFFF, "Mouse wheel to zoom");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 40, 0x00FFFFFF, "-/+ to change the number of iterations");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 30, 0x00FFFFFF, numbers);
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 20, 0x00FFFFFF, "ESC to exit");
	if (ft_strequ(world->name, "Julia"))
			mlx_string_put(world->mlx, world->win, 10, HEIGHT - 10, 0x00FFFFFF, "I = interractive mode");
	free (numbers);
}

int		main(int argc, char **argv)
{
	t_env	world;

	if (argc == 2)
	{
		if (ft_strequ("Mandelbrot", argv[1]))
			world.fract = 1;
		else if (ft_strequ("Julia", argv[1]))
			world.fract = 2;
		else if (ft_strequ("Ships", argv[1]))
			world.fract = 3;
		else
			ft_print_set();
		world.name = argv[1];
		create_window(&world);
	}
	else
		ft_print_set();
	return (0);
}

void	create_window(t_env *world)
{
	world->iter = 120;
	set_default(world);
	world->mlx = mlx_init();
	world->win = mlx_new_window(world->mlx, WIDTH, HEIGHT, world->name);
	world->img = mlx_new_image(world->mlx, WIDTH, HEIGHT);
	mlx_hook(world->win, 6, 64, mouse_move, world);
	mlx_mouse_hook(world->win, mouse_zoom, world);
	mlx_hook(world->win, 2, 3, my_key_func, world);
	if (world->fract == 1)
		mlx_loop_hook(world->mlx, ft_mandel, world);
	if (world->fract == 2)
		mlx_loop_hook(world->mlx, ft_julia, world);
	if (world->fract == 3)
		mlx_loop_hook(world->mlx, ft_ships, world);
	mlx_loop(world->mlx);
}

void	set_default(t_env *world)
{
	if (world->fract == 1)
	{
		world->zoom = 0.8;
		world->move_x = -0.5;
		world->move_y = 0.0;
	}
	if (world->fract == 2)
	{
		world->zoom = 0.8;
		world->move_x = 0.0;
		world->move_y = 0.0;
		world->constant.real = -0.8;
		world->constant.imag = 0.156;
		world->inter = 0;
	}
	if (world->fract == 3)
	{
		world->zoom = 0.8;
		world->move_x = -0.4;
		world->move_y = -0.6;
	}
}

void	ft_print_set(void)
{
	ft_putendl("1. Mandelbrot set");
	ft_putendl("2. Julia set");
	ft_putendl("3. Ships");
	exit(0);
}
