/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:18 by dzui              #+#    #+#             */
/*   Updated: 2017/03/01 16:08:31 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_zoom(int key_code, int x, int y, t_env *world)
{
	ft_putendl(ft_itoa(key_code));
	if (key_code == 4)
	{
		world->zoom *= 2;
		world->move_x += 1.5 * (x - WIDTH / 2) / (0.5 * world->zoom * WIDTH);
		world->move_y += (y - HEIGHT / 2) / (0.5 * world->zoom * HEIGHT);
	}
	if (key_code == 5 && world->zoom > 0.2)
		world->zoom /= 2;
	return (0);
}

int		mouse_move(int x, int y, t_env *world)
{
	if (world->inter == 1)
	{
		world->constant.real = 1.5 * (x - WIDTH / 2);
		world->constant.real /= (0.5 * WIDTH * world->zoom);
		world->constant.real += world->move_x;
		world->constant.imag = (y - HEIGHT / 2) / (0.5 * HEIGHT * world->zoom);
		world->constant.imag += world->move_y;
	}
	return (0);
}

int		my_key_func(int key_code, t_env *world)
{
	ft_putendl(ft_itoa(key_code));
	if (key_code == 65307)
	{
		ft_putendl("Exit!");
		exit(0);
	}
	if (key_code == 105)
	{
		if (world->inter == 0)
			world->inter = 1;
		else
			world->inter = 0;
	}
	if (key_code == 65362)
		world->move_y -= 0.05 / world->zoom;
	if (key_code == 65364)
		world->move_y += 0.05 / world->zoom;
	if (key_code == 65363)
		world->move_x += 0.05 / world->zoom;
	if (key_code == 65361)
		world->move_x -= 0.1 / world->zoom;
	event(key_code, world);
	return (0);
}

void	event(int key_code, t_env *world)
{
	if (key_code == 61 && world->iter <= 400)
		world->iter += 5;
	if (key_code == 45 && world->iter > 50)
		world->iter -= 5;
	if (key_code == 48)
		set_default(world);
}
