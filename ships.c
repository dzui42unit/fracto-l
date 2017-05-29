/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ships.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:09:07 by dzui              #+#    #+#             */
/*   Updated: 2017/02/28 15:09:17 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_ships(t_env *world)
{
	pthread_t	threads[THREADS];
	t_data		data[THREADS];
	int			i;

	clear_image(world);
	i = 0;
	while (i < THREADS)
	{
		data[i].w = world;
		data[i].y_st = HEIGHT / THREADS * i;
		data[i].y_end = HEIGHT / THREADS * (i + 1);
		pthread_create(&(threads[i]), NULL, draw_ships, &(data[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
	ft_draw_controls(world);
	return (0);
}

void	*draw_ships(void *arg)
{
	t_complex	z;
	t_complex	c;
	t_data		*info;
	int			x;

	info = (t_data*)arg;
	while (info->y_st != info->y_end)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->x = x;
			z.real = 0;
			z.imag = 0;
			c.real = 1.5 * (x - WIDTH / 2) / (0.5 * info->w->zoom * WIDTH);
			c.real += info->w->move_x;
			c.imag = (info->y_st - HEIGHT / 2) / (0.5 * info->w->zoom * HEIGHT);
			c.imag += info->w->move_y;
			check_point_ships(info, &z, &c);
			x++;
		}
		info->y_st += 1;
	}
	pthread_exit(NULL);
}

void	check_point_ships(t_data *info, t_complex *z, t_complex *c)
{
	int		n;
	double	r_init;

	n = 0;
	while (n < info->w->iter)
	{
		r_init = fabs(z->real);
		z->real = z->real * z->real - fabs(z->imag * z->imag) + c->real;
		z->imag = 2 * fabs(r_init * z->imag) + c->imag;
		if ((z->real * z->real + z->imag * z->imag) > 4.0)
			break ;
		n++;
	}
	set_color(info, n);
}
